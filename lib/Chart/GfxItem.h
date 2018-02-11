/*
 * GfxItem.h
 *
 *  Created on: 19.11.2017
 *      Author: sn
 */

#ifndef LIB_CHART_GFXITEM_H_
#define LIB_CHART_GFXITEM_H_

#include "Adafruit_GFX.h"
//#include <vector>

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

class GfxItem;

class GfxItem {
public:
	GfxItem(Adafruit_GFX &gfx, int x, int y, int w, int h, uint16_t color);	// root object

	GfxItem(GfxItem *parent, int x, int y, int w, int h, uint16_t color);

	inline int x0(){return _x;};
	inline int y0(){return _y;};
	inline int width(){return _w;};
	inline int height(){return _h;};
	inline int color(){return _color;};

	virtual void draw() {};

	GfxItem *_parent;
	Adafruit_GFX &_gfx;

protected:
	int _x;
	int _y;
	int _w;
	int _h;
	int _color;
};




#endif /* LIB_CHART_GFXITEM_H_ */
