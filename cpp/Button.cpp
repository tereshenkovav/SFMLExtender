#include "Button.h"

namespace sf {

Button::Button() 
{
}

bool Button::isMouseOver(int x, int y) 
{
	int lx = shape.getPosition().x ;
	int ly = shape.getPosition().y ;

	int w = shape.getSize().x ;
	int h = shape.getSize().y ;

	return (lx<=x)&&(ly<=y)&&(x<=lx+w)&&(y<=ly+h) ;
	
}

void Button::setButton(String caption, Color colorback, Color colorborder, Color colorfont,
			   const Font & font, int fontsize, int x, int y, int w, int h)
{
	shape.setSize(Vector2f(w,h)) ;
    shape.setFillColor(colorback) ;
	shape.setOutlineColor(colorborder) ;
	shape.setOutlineThickness(2) ;

	shape.setPosition(x,y) ;

	text.setString(caption) ;
	text.setFont(font) ;
	text.setCharacterSize(fontsize) ;
	text.setColor(colorfont) ;

	text.setPosition(x,y) ;

}

void Button::draw (RenderTarget &target, RenderStates states) const
{
	target.draw(shape) ;
	target.draw(text) ;
}

Button::~Button(void)
{
}

}