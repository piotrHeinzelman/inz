package pl.heinzelman.yyy;

import org.junit.jupiter.api.Test;
import pl.heinzelman.yyy.net.Teacher;


public class CnnApplication {

	@Test
	public void main() {

		Teacher.prepare( 8 );
		Teacher.train( 5000 );

		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 10000 );
		/**/
	}

}
