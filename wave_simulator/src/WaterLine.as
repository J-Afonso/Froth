package
{
	import flash.display.Sprite;
	
	public class WaterLine extends Sprite
	{
		public function WaterLine()
		{
			super();
			graphics.lineStyle(1, 0x0000ff);
			graphics.moveTo(0,0);
			graphics.lineTo(720, 0);
		}
	}
}