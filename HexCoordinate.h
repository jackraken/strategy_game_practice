/*
 * HexCoordinate.h
 *
 *  Created on: 2014/9/12
 *      Author: LukeWu
 */

#ifndef HEXCOORDINATE_H_
#define HEXCOORDINATE_H_

class HexCoordinate {
public:
	HexCoordinate(int xx=0,int yy=0);
	int getX()const {return x;}
	int getY()const {return y;}
	int getDis(HexCoordinate target);
	bool operator == (const HexCoordinate &a)const;
	HexCoordinate operator +(HexCoordinate a);
private:
	int x,y;
};

#endif /* HEXCOORDINATE_H_ */
