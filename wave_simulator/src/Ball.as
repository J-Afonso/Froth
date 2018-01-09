package
{
	import flash.display.Sprite;
	
	public class Ball extends Sprite
	{
		public function Ball()
		{
			super();
			graphics.beginFill(0x00ff00, 1);
			graphics.drawCircle(0,0,5);
			graphics.endFill();
		}
	}
}