import java.util.HashMap;


public class Grab {

    //  private static String myString = "my.song.mp3 11b\ngreatSong.flac 1000b\nnot3.txt 5b\nvideo.mp4 200b\ngame.exe 100b\nmov!e.mkv 10000b";
    
    private static String myString = "%as.#@!'%*(_{}.eas0 9000000b";
    
    public static void main( String[] args ) {
        
        Grab g = new Grab();
        g.solution(myString);
        
    }


    public String solution(String S) {
    	String files[] = S.split("\n");
    	
    	HashMap<String, String> fileTypeCategoryMap = getFileTypeCategoryMap();
    	
    	long musicFilesSize = 0L, imgFilesSize = 0L, movieFilesSize = 0L, otherFilesSize = 0L;
    	
    	for (String fileName : files) {
    		String fileInfo[] = fileName.split(" ");
    		String fileExtension = getFileExtension(fileInfo[0]);
    		long fileSize = getFileSize(fileInfo[1]).longValue();
//    		System.out.println("FileExt: " + fileExtension + " and size is: " + fileSize);   
    		
    		String fileCategory = fileTypeCategoryMap.get(fileExtension);
    		
    		if (fileCategory == "image") {
    			imgFilesSize += fileSize;
    		}
    		else if (fileCategory == "music") {
    			musicFilesSize += fileSize;
    		}
    		else if (fileCategory == "movie") {
    			movieFilesSize += fileSize;
    		}
    		else {
    			otherFilesSize += fileSize;
    		}
    		
    	}
    	
    	String res = "music " + musicFilesSize + "b"
    			+ "\n" + "images " + imgFilesSize + "b"
    			+ "\n" + "movies " + movieFilesSize + "b"
    			+ "\n" + "other " + otherFilesSize + "b";
    	
    	System.out.println(res);
    	
//    	System.out.println("music " + musicFilesSize + "b");
//    	System.out.println("images " + imgFilesSize + "b");
//    	System.out.println("movies " + movieFilesSize + "b");
//    	System.out.println("other " + otherFilesSize + "b");
    	
    	return res;
    }
    
    private String getFileExtension(String fileName) {
    	String fileNameParts[] = fileName.split("\\.");
    	return fileNameParts[fileNameParts.length - 1];
    }
    
    private Long getFileSize(String fileSizeString) {
    	String fileSizeStringWithoutUnit = fileSizeString.substring(0, fileSizeString.length() - 1);
    	return Long.valueOf(fileSizeStringWithoutUnit);
    }
    
    private HashMap<String, String> getFileTypeCategoryMap() {
    	HashMap<String, String> fileTypeCategoryMap = new HashMap<String, String>();
    	
    	fileTypeCategoryMap.put("mp3", "music");
    	fileTypeCategoryMap.put("aac", "music");
    	fileTypeCategoryMap.put("flac", "music");
    	
    	fileTypeCategoryMap.put("jpg", "image");
    	fileTypeCategoryMap.put("bmp", "image");
    	fileTypeCategoryMap.put("gif", "image");
    	
    	fileTypeCategoryMap.put("mp4", "movie");
    	fileTypeCategoryMap.put("avi", "movie");
    	fileTypeCategoryMap.put("mkv", "movie");
    	
    	return fileTypeCategoryMap;
    }
    
    
}

// my.song.mp3 11b\ngreatSong.flac 1000b\nnot3.txt 5b\nvideo.mp4 200b\ngame.exe 100b\nmov!e.mkv 10000b
