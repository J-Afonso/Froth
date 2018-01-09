package
{
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.geom.Point;
	
	[SWF(backgroundColor="0x000000")]
	public class WaveSimulator extends Sprite {
		
		private var mProgress:Number = 0;
		
		private var mCrestPath:CrestPath = new CrestPath();
		private var mWave:Wave = new Wave(mCrestPath);
		private var mWaterLine:WaterLine = new WaterLine();
		private var mCrest:Ball = new Ball();

		
		public function WaveSimulator() {
			this.addChild(mWaterLine);
			this.addChild(mCrestPath);
			this.addChild(mCrest);
			this.addChild(mWave);
			
			mCrestPath.y = 100;		
			mWave.y = 100;
			mWaterLine.x = -100;		
			mWaterLine.y = 300;
			
			this.addEventListener(Event.ENTER_FRAME,onTimer);
		}
		
		protected function onTimer(event:Event):void {
			mProgress += 0.001;
			var point:Point = mCrestPath.getPoint(mProgress);
			mCrest.x = point.x;
			mCrest.y = point.y + 100;
			
			mWave.step(mProgress);
		}
	}
}