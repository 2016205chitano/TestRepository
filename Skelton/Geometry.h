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
	///����X���W��Ԃ�
		///<summary>
		///<returns>��</returns>
	float Left()const;
	///<summary>
///���Y���W��Ԃ�
	///<summary>
	///<returns>��</returns>
	float Top()const;
	///<summary>
///�E��X���W��Ԃ�
	///<summary>
	///<returns>�E</returns>
	float Right()const;
	///<summary>
///����Y���W��Ԃ�
	///<summary>
	///<returns>��</returns>
	float Bottom()const;

	float Width()const;
	float Height()const;
};

struct Circle {
	Position2 center;
	float radius;
};