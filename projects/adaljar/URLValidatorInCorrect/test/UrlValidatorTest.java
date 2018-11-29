

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {

   String validScheme = "http://";
   String validHost = "www.google.com";
   String validPort = ":80";
   String validPath = "/path";
   String validQuery = "?refresh=true";

   public UrlValidatorTest(String testName) {
      super(testName);
   }



   
   public void testManualTest()
   {
      //You can use this function to implement your manual testing	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      System.out.println("TESTS: Running Manual Testing\n");


      System.out.println(urlVal.isValid("\n\nTESTING VALID SCHEMES: EXPECTED TRUE\n"));
      System.out.println(urlVal.isValid("http://www.gmail.com"));
      System.out.println(urlVal.isValid("www.gmail.com"));
      System.out.println(urlVal.isValid("https://www.gmail.com"));

      System.out.println(urlVal.isValid("\n\nTESTING INVALID SCHEMES: EXPECTED FALSE\n"));
      System.out.println(urlVal.isValid("://www.gmail.com"));
      System.out.println(urlVal.isValid("http:/www.gmail.com"));
      System.out.println(urlVal.isValid("ht://www.gmail.com"));
      System.out.println(urlVal.isValid("ccc://www.gmail.com"));
      System.out.println(urlVal.isValid("https:/www.gmail.com"));

      System.out.println(urlVal.isValid("\n\nTESTING VALID SCHEMES, VALID HOSTS: EXPECTED TRUE\n"));
      System.out.println(urlVal.isValid("http://www.gmail.com"));
      System.out.println(urlVal.isValid("http://gmail.com"));
      System.out.println(urlVal.isValid("http://192.168.1.1"));

      System.out.println(urlVal.isValid("\n\nTESTING INVALID HOSTS: EXPECTED FALSE\n"));
      System.out.println(urlVal.isValid("http://ccc.gmail.com"));
      System.out.println(urlVal.isValid("www.gmail"));
      System.out.println(urlVal.isValid("https://gmail"));

      System.out.println(urlVal.isValid("\n\nTESTING VALID SCHEMES, VALID HOSTS, VALID PORTS: EXPECTED TRUE\n"));
      System.out.println(urlVal.isValid("http://www.gmail.com"));
      System.out.println(urlVal.isValid("http://gmail.com:80"));
      System.out.println(urlVal.isValid("http://192.168.1.1:1445"));

      System.out.println(urlVal.isValid("\n\nTESTING INVALID PORTS: EXPECTED FALSE\n"));
      System.out.println(urlVal.isValid("http://www.gmail.com:bad43"));
      System.out.println(urlVal.isValid("http://gmail.com:242342234"));
      System.out.println(urlVal.isValid("http://192.168.1.1badtest"));

      System.out.println(urlVal.isValid("\n\nTESTING VALID SCHEMES, VALID HOSTS, VALID PORTS, VALID PATHS: EXPECTED TRUE\n"));
      System.out.println(urlVal.isValid("http://www.gmail.com:8080/path"));
      System.out.println(urlVal.isValid("http://gmail.com:80/path/"));
      System.out.println(urlVal.isValid("http://192.168.1.1:1445/1/2/3/4/"));
  
      System.out.println(urlVal.isValid("\n\nTESTING INVALID PATHS: EXPECTED FALSE\n"));
      System.out.println(urlVal.isValid("http://www.gmail.com:8080//oopspath"));
      System.out.println(urlVal.isValid("http://gmail.com:80////alsobadpath"));
      System.out.println(urlVal.isValid("http://192.168.1.1:1445/path/...test"));

      System.out.println(urlVal.isValid("\n\nTESTING VALID SCHEMES, VALID HOSTS, VALID PORTS, VALID PATHS, QUERIES: EXPECTED TRUE\n"));
      System.out.println(urlVal.isValid("http://www.gmail.com:8080/path?foo=bar"));
      System.out.println(urlVal.isValid("http://gmail.com:80/path?state=oregon&best=true"));
      System.out.println(urlVal.isValid("http://192.168.1.1:1445/1/2/3/4/?foo+bar=foobar"));

      System.out.println(urlVal.isValid("\n\nTESTING INVALID QUERIES: EXPECTED FALSE\n"));
      System.out.println(urlVal.isValid("http://www.gmail.com:8080/path ?s"));
      System.out.println(urlVal.isValid("http://gmail.com:80/path/?a=b=c"));
      System.out.println(urlVal.isValid("http://192.168.1.1:1445/1/2/3/4/???foo=bar"));


   }
   

   public void testYourFirstPartition()
   {
	   //You can use this function to implement your First Partition testing	  
      String[] validSchemesList = {"http://","https://","ftp://"}; 
      String[] invalidSchemesList = {"http:/","3ht://","http/", "http:", "://","///:"}; 
      UrlValidator urlVal = new UrlValidator();

      //TEST SCHEMES: VALID (TRY URLS CONTAINING THE VALID SCHEMES)
      System.out.println("\n\nTESTS: Running First Partition Testing (Valid Schemes)\n");
      for (int i = 0; i < validSchemesList.length; i++) {
         String testURL = validSchemesList[i] + validHost + validPort + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST SCHEMES: INVALID (TRY URLS CONTAINING THE INVALID SCHEMES)
      System.out.println("\n\nTESTS: Running First Partition Testing (Invalid Schemes)\n");
      for (int i = 0; i < invalidSchemesList.length; i++) {
         String testURL = invalidSchemesList[i] + validHost + validPort + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }
   
   public void testYourSecondPartition(){
		//You can use this function to implement your Second Partition testing	   
      String[] validHostList = {"www.gmail.com","gmail.com","192.168.1.1"};
      String[] invalidHostList = {"www.gmail%.com","ccc.gmail.com",""," ","badtest","gmail","www.gmail"};
      UrlValidator urlVal = new UrlValidator();

      //TEST HOST PARTITIONING: VALID (TRY URLS CONTAINING THE VALID TEST HOSTS)
      System.out.println("\n\nTESTS: Running Second Partition Testing (Valid Host)\n");
      for (int i = 0; i < validHostList.length; i++) {
         String testURL = validScheme + validHostList[i] + validPort + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST HOST PARTITIONING: INVALID (TRY URLS CONTAINING THE INVALID TEST HOSTS)
      System.out.println("\n\nTESTS: Running Second Partition Testing (Invalid Host)\n");
      for (int i = 0; i < invalidHostList.length; i++) {
         String testURL = validScheme + invalidHostList[i] + validPort + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }

   //You need to create more test cases for your Partitions if you need to 
   public void testYourThirdPartition(){
      String[] validPortList = {"",":80", ":8080", ":433", ":6789", ":562", ":539", ":1445", ":4384",":12455", ":65530"};
      String[] invalidPortList = {" ","aaa", ":bad43", ":", ":242342234", ":-0"};
      UrlValidator urlVal = new UrlValidator();

      //TEST PORT PARTITIONING: VALID (TRY URLS CONTAINING THE VALID TEST PORTS)
      System.out.println("\n\nTESTS: Running Third Partition Testing (Valid Port)\n");
      for (int i = 0; i < validPortList.length; i++) {
         String testURL = validScheme + validHost + validPortList[i] + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST PORT PARTITIONING: INVALID (TRY URLS CONTAINING THE INVALID TEST PORTS)
      System.out.println("\n\nTESTS: Running Third Partition Testing (Invalid Port)\n");
      for (int i = 0; i < invalidPortList.length; i++) {
         String testURL = validScheme + validHost + invalidPortList[i] + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }

   public void testYourFourthPartition(){  
      String[] validPathList = {"", "/", "/path", "/path/", "/foo/bar", "/foo/bar/", "/1/2/3/4/" };
      String[] invalidPathList = {"/path/...test", "badpath", "////alsobadpath", "//oopspath"};
      UrlValidator urlVal = new UrlValidator();

      //TEST QUERY PARTITIONING: VALID (TRY URLS CONTAINING THE VALID TEST PATHS)
      System.out.println("\n\nTESTS: Running Fourth Partition Testing (Valid Path)\n");
      for (int i = 0; i < validPathList.length; i++) {
         String testURL = validScheme + validHost + validPort + validPathList[i];
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST QUERY PARTITIONING: INVALID (TRY URLS CONTAINING THE INVALID TEST PATHS)
      System.out.println("\n\nTESTS: Running Fourth Partition Testing (Invalid Path)\n");
      for (int i = 0; i < invalidPathList.length; i++) {
         String testURL = validScheme + validHost + validPort + invalidPathList[i];
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }

   public void testYourFifthPartition(){  
      String[] validQueryList = {"", "?foo=bar", "?state=oregon&best=true", "?foo+bar=foobar"};
      String[] invalidQueryList = {"/ ?s", "?a=b=c", "?d e f", "???foo=bar"};
      UrlValidator urlVal = new UrlValidator();

      //TEST QUERY PARTITIONING: VALID (TRY URLS CONTAINING THE VALID TEST QUERIES)
      System.out.println("\n\nTESTS: Running Fifth Partition Testing (Valid Query)\n");
      for (int i = 0; i < validQueryList.length; i++) {
         String testURL = validScheme + validHost + validPort + validPath + validQueryList[i];
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST QUERY PARTITIONING: INVALID (TRY URLS CONTAINING THE INVALID TEST QUERIES)
      System.out.println("\n\nTESTS: Running Fifth Partition Testing (Invalid query)\n");
      for (int i = 0; i < invalidQueryList.length; i++) {
         String testURL = validScheme + validHost + validPort + validPath + invalidQueryList[i];
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }

   private KnownRes[] resSchemes = {
      new KnownRes("http://", true),
      new KnownRes("https://", true),
      new KnownRes("ftp://", true),

      new KnownRes("http:/", false),
      new KnownRes("3ht://", false),
      new KnownRes("http/", false),
      new KnownRes("://", false),            
      new KnownRes("///:", false)
   };

   private KnownRes[] resHost = {
      new KnownRes("www.gmail.com", true),
      new KnownRes("gmail.com", true),
      new KnownRes("192.168.1.1", true),

      new KnownRes("www.gmail%.com", false),
      new KnownRes("ccc.gmail.com", false),
      new KnownRes("", false),            
      new KnownRes(" ", false),      
      new KnownRes("www.gmail", false), 
      new KnownRes("gmail", false), 
      new KnownRes("badtest", false)
   };

   private KnownRes[] resPorts = {
      new KnownRes("", true),
      new KnownRes(":80", true),
      new KnownRes(":8080", true),  
      new KnownRes(":433", true),
      new KnownRes(":6789", true),
      new KnownRes(":562", true),
      new KnownRes(":539", true),
      new KnownRes(":1445", true),
      new KnownRes(":4384", true),
      new KnownRes(":12455", true),
      new KnownRes(":65530", true),
         
      new KnownRes(" ", false),
      new KnownRes("aaa", false),
      new KnownRes(":bad43", false),
      new KnownRes(":", false),
      new KnownRes(":242342234", false),
      new KnownRes(":-0", false)
   };


   private KnownRes[] resPaths = {
      new KnownRes("", true),
      new KnownRes("/", true),
      new KnownRes("/path", true),
      new KnownRes("/path/", true),
      new KnownRes("/foo/bar", true),
      new KnownRes("/foo/bar/", true),
      new KnownRes("/1/2/3/4/", true),

      new KnownRes("/path/...test", false),
      new KnownRes("badpath", false),
      new KnownRes("////alsobadpath", false),
      new KnownRes("//oopspath", false)
   };


   private KnownRes[] resQueries = {
      new KnownRes("", true),
      new KnownRes("?foo=bar", true),
      new KnownRes("?state=oregon&best=true", true),
      new KnownRes("?foo+bar=foobar", true),

      new KnownRes("/ ?s", false),
      new KnownRes("?a=b=c", false),
      new KnownRes("?d e f", false),
      new KnownRes("???foo=bar", false)
   };


   private KnownRes[][] partsToCheck = {resSchemes, resHost, resPorts, resPaths, resQueries};

   public void testIsValid() {
      //You can use this function for programming based testing
      System.out.println("\n\nTESTS: Running PROGRAMMATICAL TESTING\n");

      UrlValidator urlVal = new UrlValidator();

      int countWronglyPassed = 0;
      int countWronglyFailed = 0;

      for (KnownRes scheme : resSchemes) {
         for (KnownRes host : resHost) {
            for (KnownRes port : resPorts) {
               for (KnownRes path : resPaths) {
                  for (KnownRes query : resQueries) {

                     String testURL = scheme.item + host.item + port.item + path.item + query.item;                  // Make the URL
                     boolean resExpected = scheme.valid && host.valid && port.valid && path.valid && query.valid;    // Expected result
                     boolean resActual = urlVal.isValid(testURL);                                                    // Actual returned result

                     if (resExpected != resActual) {
                        if (resExpected) {
                            countWronglyFailed++;
                            System.out.println("Wrong result (FALSE - NEG) from isValid with URL:  " + testURL);
                        }
                        else {
                            countWronglyPassed++;
                            System.out.println("Wrong result (FALSE - POS) from isValid with URL:  " + testURL);
                        }
                     }
                  }
               }
            }
         }
      }

      int totalURLsChecked = 1;

      for (KnownRes[] segments : partsToCheck) {
         totalURLsChecked *= segments.length;
      }

      int totalWrongAns = countWronglyPassed + countWronglyFailed;

      System.out.println("\n\nProgrammatical Test Result:\n");
      System.out.println(countWronglyFailed + " valid URLs were expected to passed, but failed instead.");
      System.out.println(countWronglyPassed + " invalid URLs wrongly passed, they should have failed.");
      System.out.println("Wrong Answers: " + totalWrongAns + " out of " + totalURLsChecked + ".");
   }

}
