/*
 * Main.cpp
 *
 *  Created on: Aug 15, 2022
 *      Author: ysiyer
 */

#include <Shapes.h>
#include <cassert>

int main()
{
	vector<Shapes*> ShapesCollection;
	Rectangle* r = new Rectangle(2,3);
	ColoredShape* cr = new ColoredShape(* new Rectangle(2, 3), "Green");
	FinishedShape* fcr = new FinishedShape(* new ColoredShape(* new Rectangle(2, 3), "Blue"), "Oiled");

	ShapesCollection.push_back(r);
	ShapesCollection.push_back(cr);
	ShapesCollection.push_back(fcr);

	for (auto s: ShapesCollection)
		s->describe();

	cout << calcTotalArea(ShapesCollection) << endl;

	return 0;
}

