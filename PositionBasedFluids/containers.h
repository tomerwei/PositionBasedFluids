#ifndef CONTAINERS_H
#define CONTAINERS_H

struct Particle {
	Particle(glm::vec3 pos, float mass) {
		this->oldPos = pos;
		this->mass = mass;
		newPos = glm::vec3(0, 0, 0);
		velocity = glm::vec3(0, 0, 0);
		force = glm::vec3(0, 0, 0);
		deltaP = glm::vec3(0, 0, 0);
		lambda = 0;
		pConstraint = 0;
	}

	glm::vec3 oldPos;
	glm::vec3 newPos;
	glm::vec3 velocity;
	glm::vec3 force;
	glm::vec3 deltaP;
	float mass;
	float lambda;
	float pConstraint;
	std::vector<Particle*> neighbors;
};

struct Cell {
	std::vector<Particle*> particles;
	std::vector<Cell*> neighbors;

	void addParticle(Particle &p) {
		particles.push_back(&p);
	}

	void addNeighbor(Cell &c) {
		neighbors.push_back(&c);
	}
};

#endif