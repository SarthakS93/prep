
import java.util.*;


/**
 * Hello world!
 *
 */
public class MoveInSync 
{
    public static void main( String[] args ) {
    	
    	int t;
//    	System.out.println("Enter n");
    	Scanner sc = new Scanner(System.in);
    	String tString = sc.nextLine();
    	t = Integer.parseInt(tString);
    	while (t > 0) {
    		InputClass input = takeInput(sc);
    		long output = getObstacles(input.getN(), input.getX(), input.getY());
    		System.out.println(output);
    		t--;
    	}
    	
    	
    }
    
    private static InputClass takeInput(Scanner sc) {
//    	System.out.println("Enter input string");
    	String inputString = sc.nextLine();
//    	System.out.println(inputString);
    	
    	String[] inputArray = inputString.split(" ");
    	Integer n = Integer.valueOf(inputArray[0]);
    	
    	String posString = inputArray[1];
    	String posStringArray[] = posString.split(",");
    	String xString = posStringArray[0].substring(1);
    	String yString = posStringArray[1].substring(0, posStringArray[1].length() - 1);
    	Integer x = Integer.valueOf(xString);
    	Integer y = Integer.valueOf(yString);
    	
//    	System.out.println(x + " and " + y);
    	
    	return new InputClass(n.intValue(), x.intValue(), y.intValue());
    }
    
    
    private static long getObstacles(int n, int queenXPos, int queenYPos) {
//    	System.out.println("N: " + n + ", X: " + queenXPos + ", Y: " + queenYPos);
    	long queenMoves = getNumberOfMoves(n, queenXPos, queenYPos);
    	long totalNumberOfMoves = n * n;
    	return totalNumberOfMoves - queenMoves;
    }
    
    private static long getNumberOfMoves(int n, int x, int y) {
    	long moves = 0L;
    	
    	for (int i = 1; i <= 8; i++) {
    		moves += getNumberOfMovesForADirection(x, y, n, i);
    	}
    	
    	return moves;
    }
    
    private static long getNumberOfMovesForADirection(int x, int y, int n, int moveType) {
    	long moves = 0;
    	int nextX = x, nextY = y;
    	
    	while (true) {
    		if (moveType == 1) {
    			nextX = nextX;
    			nextY = nextY + 1;
        	}
        	else if (moveType == 2) {
        		nextX = nextX + 1;
        		nextY = nextY + 1;
    		}
    		else if (moveType == 3) {
    			nextX = nextX + 1;
    			nextY = nextY;
    		}
    		else if (moveType == 4) {
    			nextX = nextX + 1;
    			nextY = nextY - 1;
    		}
    		else if (moveType == 5) {
    			nextX = nextX;
    			nextY = nextY - 1;
    		}
    		else if (moveType == 6) {
    			nextX = nextX - 1;
    			nextY = nextY - 1;
    		}
    		else if (moveType == 7) {
    			nextX = nextX - 1;
    			nextY = nextY;
    		}
    		else if (moveType == 8) {
    			nextX = nextX - 1;
    			nextY = nextY + 1;
    		}
    		
    		boolean isNextMoveValid = checkIfValidMove(n, nextX, nextY);
    		if (isNextMoveValid) {
    			moves++;
    		}
    		else {
    			break;
    		}
    	}
    	
    	return moves;
    }
    
    private static boolean checkIfValidMove(int n, int x, int y) {
    	if (x > n || y > n || x < 1 || y < 1) {
    		return false;
    	}
    	else {
    		return true;
    	}
    }
}

class InputClass {
	private int n;
	
	private int x;
	
	private int y;
	
	public InputClass() {}
	
	public InputClass(int n, int x, int y) {
		this.n = n;
		this.x = x;
		this.y = y;
	}
	
	public int getN() {
		return n;
	}
	public void setN(int n) {
		this.n = n;
	}
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
	
}
