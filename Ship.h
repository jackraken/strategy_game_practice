/*
 * Ship.h
 *
 *  Created on: 2014/8/6
 *      Author: LukeWu
 */

#ifndef SHIP_H_
#define SHIP_H_
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Renderer.h"
#include "HexCoordinate.h"
#include "Order.h"

class HexMap;

class Ship {
public:
	Ship(float map_x, float map_y, float map_unit_len);
	void render(Renderer* renderer);
	void update();
	void keyActive(int key, int action);
	float mouseActive(int button, glm::vec3 pos, glm::vec3 dir);
	void setMode(int button);
	int getMode(){return mode;}
	HexCoordinate getCoordinate(){return coordinate;}
	void addOrder(Order *order);
	void clearOrder(){order_list.clear();}
	void move(float map_x,float map_y);
	void addAP(){ap += ap_per_turn;};
	int getAP(){return ap;}
	static void setMap(HexMap *m){map = m;}
private:
	static HexMap *map;
	HexCoordinate coordinate;
	float x,y,z;
	int mode;// 0->none 1->touched 2->selected
	std::vector<Order *>order_list;
	std::vector<float> obj_vertex;
	std::vector<float> obj_uv;
	std::vector<float> obj_normal;
	glm::vec3 aabb_bottom_left, aabb_top_right,aabb_bottom_left_model, aabb_top_right_model;
	glm::mat4 model_matrix;
	GLuint vbo_vertex, vbo_uv, vbo_normal;
	unsigned int texture_id, texture_unif;
	int ap_per_turn;
	int ap;//action points
};

#endif /* SHIP_H_ */
