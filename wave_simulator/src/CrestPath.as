package
{
	import flash.display.Sprite;
	import flash.geom.Point;
	
	public class CrestPath extends Sprite {
		private static var DRAW_HANDLES:Boolean = false;
		
		private static var _pointA:Point = new Point(0, 200);
		private static var _pointAHandle:Point = new Point(120, 200);
		
		private static var _pointB:Point = new Point(300, 1);
		private static var _pointBHandleA:Point = new Point(245, 0);
		private static var _pointBHandleB:Point = new Point(380, 3);
		
		private static var _pointC:Point = new Point(420, 250);
		private static var _pointCHandle:Point = new Point(420, 220);
		
		private static var _bezierA:CubicBezier = new CubicBezier(_pointA, _pointAHandle, _pointBHandleA, _pointB);
		private static var _bezierB:CubicBezier = new CubicBezier(_pointB, _pointBHandleB, _pointCHandle, _pointC);
		
		public function CrestPath()
		{
			super();
			draw();
		}
		
		private function draw():void {
			graphics.clear();
			
			if (DRAW_HANDLES) {
				graphics.beginFill(0xff0000, 1);
				graphics.drawCircle(_pointA.x, _pointA.y, 2);
				graphics.drawCircle(_pointB.x, _pointB.y, 2);
				graphics.drawCircle(_pointC.x, _pointC.y, 2);
				graphics.drawCircle(_pointAHandle.x, _pointAHandle.y, 2);
				graphics.drawCircle(_pointBHandleA.x, _pointBHandleA.y, 2);
				graphics.drawCircle(_pointBHandleB.x, _pointBHandleB.y, 2);
				graphics.drawCircle(_pointCHandle.x, _pointCHandle.y, 2);
				graphics.endFill();
				
				graphics.lineStyle(1,0xff0000);
				graphics.moveTo(_pointA.x, _pointA.y);
				graphics.lineTo(_pointAHandle.x, _pointAHandle.y);			
				graphics.moveTo(_pointB.x, _pointB.y);
				graphics.lineTo(_pointBHandleA.x, _pointBHandleA.y);
				graphics.moveTo(_pointB.x, _pointB.y);
				graphics.lineTo(_pointBHandleB.x, _pointBHandleB.y);
				graphics.moveTo(_pointC.x, _pointC.y);
				graphics.lineTo(_pointCHandle.x, _pointCHandle.y);
			}
			
			graphics.lineStyle(1,0xff0000);
			graphics.moveTo(_pointA.x, _pointA.y);
			graphics.cubicCurveTo(_pointAHandle.x, _pointAHandle.y, _pointBHandleA.x, _pointBHandleA.y, _pointB.x, _pointB.y);
			graphics.cubicCurveTo(_pointBHandleB.x, _pointBHandleB.y, _pointCHandle.x, _pointCHandle.y, _pointC.x, _pointC.y);
		}
		
		public function getPoint(progress:Number):Point {
			progress = Math.max(progress, 0);
			progress = Math.min(progress, 1);
			
			if(progress <= 0.5) {
				progress *= 2;
				return _bezierA.getPoint(progress);
			} else {		
				progress -= 0.5;
				progress *= 2;
				return _bezierB.getPoint(progress);
			}
		}
		
		public function start():Point {
			return _pointA;
		}
	}
}