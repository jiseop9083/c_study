#include "data.h"


int board[21][12] = {
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{5,0,0,0,0,0,0,0,0,0,0,5}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,0,0,0,0,0,0,0,0,0,0,3}, 
{3,3,3,3,3,3,3,3,3,3,3,3}};

/*struct fallingData {
	int type;
	int rotating;
	int x;
	int y;
};
*/
int shape[7][4][4][4] = { { // ����, ȸ��, 4X4
{{0,1,0,0}, //type 1
{ 0,1,0,0},
{ 0,1,0,0},
{ 0,1,0,0}},

{{0,0,0,0},
{ 0,0,0,0},
{ 1,1,1,1},
{ 0,0,0,0}},

{{0,0,1,0},
{ 0,0,1,0},
{ 0,0,1,0},
{ 0,0,1,0}},

{{0,0,0,0},
{ 1,1,1,1},
{ 0,0,0,0},
{ 0,0,0,0}}},


{{{0,0,0,0}, //type2
{  0,1,1,0},
{  0,1,1,0},
{  0,0,0,0}},

{{0,0,0,0},
{ 0,1,1,0},
{ 0,1,1,0},
{ 0,0,0,0}},

{{0,0,0,0},
{ 0,1,1,0},
{ 0,1,1,0},
{ 0,0,0,0}},

{{0,0,0,0},
{ 0,1,1,0},
{ 0,1,1,0},
{ 0,0,0,0}}} ,


{{{0,0,0,0}, //type3
{  0,1,0,0},
{  0,1,1,1},
{  0,0,0,0}},

{{0,0,1,0},
{ 0,0,1,0},
{ 0,1,1,0},
{ 0,0,0,0}},

{{0,0,0,0},
{ 1,1,1,0},
{ 0,0,1,0},
{ 0,0,0,0}},

{{0,0,0,0},
{ 0,1,1,0},
{ 0,1,0,0},
{ 0,1,0,0}}}, 


{{{0,0,0,0}, //type4
{  0,1,1,1},
{  0,1,0,0},
{  0,0,0,0}},

{{0,1,0,0},
{ 0,1,0,0},
{ 0,1,1,0},
{ 0,0,0,0}},

{{0,0,0,0},
{ 0,0,1,0},
{ 1,1,1,0},
{ 0,0,0,0}},

{{0,0,0,0},
{ 0,1,1,0},
{ 0,0,1,0},
{ 0,0,1,0}}},


{{{0,0,0,0}, //type5
{  0,1,1,0},
{  0,0,1,1},
{  0,0,0,0}},

{{0,0,1,0},
{ 0,1,1,0},
{ 0,1,0,0},
{ 0,0,0,0}},

{{0,0,0,0},
{ 1,1,0,0},
{ 0,1,1,0},
{ 0,0,0,0}},

{{0,0,0,0},
{ 0,0,1,0},
{ 0,1,1,0},
{ 0,1,0,0}}},


{{{0,0,0,0}, //type6
{  0,1,1,0 },
{  1,1,0,0 },
{  0,0,0,0 }},

{{0,0,0,0},
{ 0,1,0,0},
{ 0,1,1,0},
{ 0,0,1,0} },

{{0,0,0,0},
{ 0,0,1,1},
{ 0,1,1,0},
{ 0,0,0,0} },

{{0,1,0,0},
{ 0,1,1,0},
{ 0,0,1,0},
{ 0,0,0,0} }},


{{{0,0,0,0},
{  0,1,1,1},
{  0,0,1,0},
{  0,0,0,0}},

{{0,1,0,0},
{ 0,1,1,0},
{ 0,1,0,0},
{ 0,0,0,0} },

{{0,0,0,0},
{ 0,1,0,0},
{ 1,1,1,0},
{ 0,0,0,0} },

{{0,0,0,0},
{ 0,0,1,0},
{ 0,1,1,0},
{ 0,0,1,0} }}};