package {
	import flash.display.Sprite;
	import flash.geom.Matrix3D;
	import flash.geom.Point;
	import flash.geom.Vector3D;
	
	public class Wave extends Sprite {
		
		private var _crest:CrestPath;
		
		public function Wave (crest:CrestPath) {
			_crest = crest;
		}
		
		public function step(progress:Number):void {
			
			graphics.clear();
			graphics.lineStyle(2,0x00ff00);	
			
			/********************************
			 * FIRST LINE SEGMENT
			 ********************************/
			
			var start:Point = _crest.start();
			var crest:Point = _crest.getPoint(progress);
			
			////////// First control point. ///////////////
			
			var startVectorA:Vector3D = new Vector3D(start.x, start.y);	
			var controlPointA:Vector3D = new Vector3D(crest.x - start.x, crest.y - start.y);	
			var angleBetweenA:Number = Vector3D.angleBetween(controlPointA, Vector3D.X_AXIS) * 180 / Math.PI;  ;	
			
			var rotationMatrixA:Matrix3D = new Matrix3D; 
			rotationMatrixA.appendRotation(angleBetweenA * progress, Vector3D.Z_AXIS);
			controlPointA = rotationMatrixA.transformVector(controlPointA);
			
			var vectorASize:Number = controlPointA.normalize();
			controlPointA.scaleBy(vectorASize * 0.2);
			controlPointA = controlPointA.add(startVectorA);
			
			graphics.moveTo(start.x, start.y);	
			graphics.lineTo(controlPointA.x, controlPointA.y);
			
			////////// Second control point. ///////////////
			
			var startVectorB:Vector3D = new Vector3D(crest.x, crest.y);	
			var controlPointB:Vector3D = new Vector3D(start.x - crest.x, start.y - crest.y);	
			
			var angleBetweenB:Number = Vector3D.angleBetween(controlPointB, Vector3D.Y_AXIS) * 180 / Math.PI;  ;		
			var rotationMatrixB:Matrix3D = new Matrix3D; 
			rotationMatrixB.appendRotation(angleBetweenB * progress, Vector3D.Z_AXIS);
			controlPointB = rotationMatrixB.transformVector(controlPointB);
			
			var vectorBSize:Number = controlPointB.normalize();
			controlPointB.scaleBy(vectorBSize * 0.2);
			controlPointB = controlPointB.add(startVectorB);
			
			graphics.moveTo(startVectorB.x, startVectorB.y);	
			graphics.lineTo(controlPointB.x, controlPointB.y);
			
			graphics.moveTo(start.x, start.y);	
			graphics.cubicCurveTo(controlPointA.x, controlPointA.y, 
				controlPointB.x, controlPointB.y, crest.x, crest.y);
			
			/********************************
			 * SECOND LINE SEGMENT
			 ********************************/						   
			
			////////// First control point. ///////////////
			
			var endPoint:Vector3D = new Vector3D(crest.x + vectorASize, start.y);	
			
			var startVectorC:Vector3D = new Vector3D(crest.x, crest.y);	
			var controlPointC:Vector3D = new Vector3D(endPoint.x - crest.x, endPoint.y - crest.y);	
			var angleBetweenC:Number = Vector3D.angleBetween(controlPointC, new Vector3D(-0.5, 0.5, 0)) * 180 / Math.PI;  ;	
			
			var rotationMatrixC:Matrix3D = new Matrix3D; 
			rotationMatrixC.appendRotation(angleBetweenC * progress, Vector3D.Z_AXIS);
			controlPointC = rotationMatrixC.transformVector(controlPointC);
			
			var vectorCSize:Number = controlPointC.normalize();
			controlPointC.scaleBy(vectorCSize * 0.4);		
			controlPointC = controlPointC.add(startVectorC);
			
			graphics.moveTo(crest.x, crest.y);	
			graphics.lineTo(controlPointC.x, controlPointC.y);
			
			////////// Second control point. ///////////////
			
			var startVectorD:Vector3D = endPoint.clone();
			var controlPointD:Vector3D = new Vector3D(crest.x - endPoint.x, crest.y - endPoint.y);	
			
			var angleBetweenD:Number = Vector3D.angleBetween(controlPointD, new Vector3D(-1, 0, 0)) * -180 / Math.PI;  ;		
			var rotationMatrixD:Matrix3D = new Matrix3D; 
			rotationMatrixD.appendRotation(angleBetweenD * progress, Vector3D.Z_AXIS);
			controlPointD = rotationMatrixD.transformVector(controlPointD);
			
			var vectorDSize:Number = controlPointD.normalize();
			controlPointD.scaleBy(vectorDSize * 0.4);
			controlPointD = controlPointD.add(startVectorD);
			
			graphics.moveTo(startVectorD.x, startVectorD.y);	
			graphics.lineTo(controlPointD.x, controlPointD.y);
			
			graphics.moveTo(crest.x, crest.y);
			graphics.cubicCurveTo(controlPointC.x, controlPointC.y, 
				controlPointD.x, controlPointD.y, 
				endPoint.x, endPoint.y);
			
			
			
		}
	}
}