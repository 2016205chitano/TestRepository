#pragma once

struct Vector2 {
	float x, y;
};


using Position2 = Vector2;

struct Rect {
	Position2 center;
	float w;
	float h;
	///<summary>
	///左のX座標を返す
		///<summary>
		///<returns>左</returns>
	float Left()const;
	///<summary>
///上のY座標を返す
	///<summary>
	///<returns>上</returns>
	float Top()const;
	///<summary>
///右のX座標を返す
	///<summary>
	///<returns>右</returns>
	float Right()const;
	///<summary>
///下のY座標を返す
	///<summary>
	///<returns>下</returns>
	float Bottom()const;

	float Width()const;
	float Height()const;
};

struct Circle {
	Position2 center;
	float radius;
};