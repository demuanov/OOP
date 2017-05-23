#include "Shapes.h"
#include <ctime>
#include <random>
enum shape { POINT, CIRCLE, RECTANGLE, SQUARE, POLYLINE, POLYGON };



long double randreal() 
{
	return ((long double)(rand() % 1000) / (long double)(rand() % 10));
}




Point Newpoint()
{
	Point newpoint( "Point ¹(" + ToString( rand() ) + ") ", randreal(), randreal() );
	return newpoint;
}

Shape figure( int type ) 
{
	Shape shape;
	switch ( type )
	{

		case POINT:
		{
			shape = Newpoint();
			break;
		}

		case CIRCLE: 
		{
			Point  center = Newpoint();
			Circle newcircle( "Circle ¹(" + ToString( rand() ) + ")", center, randreal());
			shape = newcircle;
			break;
		}

		case RECTANGLE: {
			Point p1 = Newpoint();
			Point p2( "Point ¹(" + ToString( rand() )+")", p1.getx() + abs( randreal() ), p1.gety() - abs( randreal() ));
			Rect newrect( "Rect ¹(" + ToString( rand() ) + ")", p1, p2 );
			shape = newrect;
			break;
		}

		case SQUARE: 
		{
			Point p1 = Newpoint();
			double delta = abs( randreal() );
			Point p2 = Point( "Point ¹(" + ToString( rand() )+")", p1.getx() + delta, p1.gety() );
			Point p3 = Point( "Point ¹(" + ToString( rand() ) + ")", p2.getx(), p2.gety() - delta);
			Point p4 = Point( "Point ¹(" + ToString( rand() ) + ")", p3.getx()-delta, p3.gety()  );
			Square newsquare( "Square ¹(" + ToString( rand() ) + ")", p1, p2, p3, p4 );
			shape = newsquare;
			break;
		}

		case POLYLINE:
		{
			int quantity = rand();
		
			Polyline newpolyline( "Polyline ¹(" + ToString( rand() )+")" );
			for ( int i = 0; i <= quantity; i++ )
			{
				Point  point = Newpoint();
				newpolyline.AddPoint( point );
			}
			shape = newpolyline;
			break;
		}

		case POLYGON:
		{
			int quantity = rand();
			Polygon newpolygon( "Polygon ¹(" + ToString( rand() )+")" );
			for ( int i = 0; i <= quantity; i++ ) 
			{
				Point  point = Newpoint();
				newpolygon.AddPoint( point );
			}
			shape = newpolygon;
			break;
		}
	}
	return shape;
}