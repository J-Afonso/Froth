package
{
	import flash.display.Graphics;
	import flash.geom.Point;
	
	public class CubicBezier
	{
		protected static const PRECISION:Number = 1e-5;
		protected var _start:Point;
		protected var _startControl:Point;
		protected var _endControl:Point;
		protected var _end:Point;
		
		public function CubicBezier(startPos:Point = null, startControlPos:Point = null, endControlPos:Point = null, endPos:Point = null)
		{
			_start = startPos ? startPos : new Point();
			_startControl = startControlPos ? startControlPos : new Point();
			_endControl = endControlPos ? endControlPos : new Point();
			_end = endPos ? endPos : new Point();
		}
		
		public function get start():Point { return _start; }
		public function set start(value:Point):void { _start = value; }
		
		public function get startControl():Point { return _startControl; }
		public function set startControl(value:Point):void { _startControl = value; }
		
		public function get endControl():Point { return _endControl; }
		public function set endControl(value:Point):void { _endControl = value; }
		
		public function get end():Point { return _end; }
		public function set end(value:Point):void { _end = value; }
		
		public function clone():CubicBezier
		{
			return new CubicBezier(start.clone(), startControl.clone(), endControl.clone(), end.clone());
		}
		
		public function getPoint(time:Number):Point
		{
			var f:Number = 1 - time;
			var f2:Number = f * f;
			var t2:Number = time * time;
			return new Point(
				start.x * f2 * f + startControl.x * 3 * f2 * time + endControl.x * 3 * t2 * f + end.x * t2 * time,
				start.y * f2 * f + startControl.y * 3 * f2 * time + endControl.y * 3 * t2 * f + end.y * t2 * time
			);
		}
	}
}