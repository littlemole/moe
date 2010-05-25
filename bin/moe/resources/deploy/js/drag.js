var i_am_dragging = false;
var dragging_x = 0;
var dragging_y = 0;

function MouseDown()
{
	i_am_dragging = true;
	dragging_x = window.event.screenX;
	dragging_y = window.event.screenY;
}

function MouseUp()
{
	i_am_dragging = false;
}

function MouseMove()
{
	if ( i_am_dragging )
	{
		
		var dx = dragging_x-window.event.screenX;
		var dy = dragging_y-window.event.screenY;

		if ( dx > 0 || dx < -0 )
		{
			external.Frame.View.Left -= dx;
			dragging_x = window.event.screenX;
		}
		if ( dy > 0 || dy < -0 )
		{
			external.Frame.View.Top  -= dy;
			dragging_y = window.event.screenY;
		}

	}
}

function draggable(id)
{
	var e = document.getElementById(id);
	if (!e)
	  return;

  e.onmousemove = MouseMove;
  e.onmousedown = MouseDown;
  e.onmouseup   = MouseUp; 
  e.onmouseout  = MouseUp;
}

