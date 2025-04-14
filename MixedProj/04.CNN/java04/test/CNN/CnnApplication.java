package CNN;

import org.junit.Test;

public class CnnApplication {




	@Test
	public void mainTest() {

		Teacher teacher = new Teacher();
		teacher.prepare( 8 );

		teacher.train( 1000 );
		teacher.test( 1000 );

	}

}
