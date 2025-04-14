package CNN;

import org.junit.Test;

public class CnnApplication {

	@Test
	public void mainTest() {

		Teacher teacher = new Teacher();
		teacher.prepare( 8 );

		teacher.train( 10 );
		teacher.test( 100 );

		teacher.train( 10 );
		teacher.test( 100 );

		teacher.train( 10 );
		teacher.test( 100 );

		teacher.train( 100 );
		teacher.test( 100 );

		teacher.train( 100 );
		teacher.test( 100 );

	}

}
