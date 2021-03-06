/*
 * TurnCounter.h
 *
 *  Created on: 2014/9/6
 *      Author: LukeWu
 */

#ifndef TURNCOUNTER_H_
#define TURNCOUNTER_H_
#include <vector>
#include "Ship.h"

class Renderer;

class TurnCounter {
public:
	TurnCounter(std::vector<Ship> &list);
	void render(Renderer *renderer);
	void update();
	void keyActive(int key);
	float mouseActive(int button, int x_pos, int y_pos);
	void setMode(int next_mode){mode = next_mode;}
private:
	bool avilible;
	int mode;
	std::vector<Ship> &ship_list;
	std::vector<float> obj_vertex;
	std::vector<float> obj_uv;
	std::vector<float> obj_normal;
	glm::mat4 model_matrix;
	unsigned int vbo_vertex, vbo_uv, vbo_normal;
	unsigned int texture_id, texture_unif;
};

#endif /* TURNCOUNTER_H_ */
