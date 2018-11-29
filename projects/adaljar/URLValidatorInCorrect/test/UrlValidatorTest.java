

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {

   String validScheme = "http://";
   String validAuthority = "www.google.com";
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
      System.out.println("TESTS: Running Manual Testing");


      int failCount = 0;

      //EXPECTED: TRUE
      System.out.println(urlVal.isValid("http://www.gmail.com"));

      System.out.println(urlVal.isValid("www.gmail.com"));

      System.out.println(urlVal.isValid("https://www.gmail.com"));

      //EXPECTED: FALSE
      System.out.println(urlVal.isValid("://www.gmail.com"));

      System.out.println(urlVal.isValid("ccc://www.gmail.com"));

      System.out.println(urlVal.isValid("https:/www.gmail.com"));

   }
   
   
   public void testYourFirstPartition()
   {
	   //You can use this function to implement your First Partition testing	  
      String[] validSchemesList = {"http://","https://","","ftp://"}; 
      String[] invalidSchemesList = {"http:/","3ht://","http/", "http:", "://","///:"}; 
      UrlValidator urlVal = new UrlValidator();

      //TEST SCHEMES: VALID (TRY URLS CONTAINING THE VALID SCHEMES)
      System.out.println("\n\nTESTS: Running First Partition Testing (Valid Schemes)");
      for (int i = 0; i < validSchemesList.length; i++) {
         String testURL = validSchemesList[i] + validAuthority + validPort + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST SCHEMES: INVALID (TRY URLS CONTAINING THE INVALID SCHEMES)
      System.out.println("\n\nTESTS: Running First Partition Testing (Invalid Schemes)");
      for (int i = 0; i < invalidSchemesList.length; i++) {
         String testURL = invalidSchemesList[i] + validAuthority + validPort + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }
   
   public void testYourSecondPartition(){
		//You can use this function to implement your Second Partition testing	   
      String[] validAuthorityList = {"www.gmail.com","gmail.com","192.168.1.1"};
      String[] invalidAuthorityList = {"www.gmail%.com","ccc.gmail.com",""," ","badtest","gmail","www.gmail"};
      UrlValidator urlVal = new UrlValidator();

      //TEST AUTHORITY PARTITIONING: VALID (TRY URLS CONTAINING THE VALID TEST AUTHORITY)
      System.out.println("\n\nTESTS: Running Second Partition Testing (Valid Authority)");
      for (int i = 0; i < validAuthorityList.length; i++) {
         String testURL = validScheme + validAuthorityList[i] + validPort + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST AUTHORITY PARTITIONING: INVALID (TRY URLS CONTAINING THE INVALID TEST AUTHORITY)
      System.out.println("\n\nTESTS: Running Second Partition Testing (Invalid Authority)");
      for (int i = 0; i < invalidAuthorityList.length; i++) {
         String testURL = validScheme + invalidAuthorityList[i] + validPort + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }

   //You need to create more test cases for your Partitions if you need to 
   public void testYourThirdPartition(){
      String[] validPortList = {"",":80", ":8080", ":433", ":6789", ":265", ":935", ":1115", ":5858",":15455", ":65530"};
      String[] invalidPortList = {" ","aa",":-4", ":test32", ":", ":242342234"};
      UrlValidator urlVal = new UrlValidator();

      //TEST PORT PARTITIONING: VALID (TRY URLS CONTAINING THE VALID TEST PORTS)
      System.out.println("\n\nTESTS: Running Third Partition Testing (Valid Port)");
      for (int i = 0; i < validPortList.length; i++) {
         String testURL = validScheme + validAuthority + validPortList[i] + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST PORT PARTITIONING: INVALID (TRY URLS CONTAINING THE INVALID TEST PORTS)
      System.out.println("\n\nTESTS: Running Third Partition Testing (Invalid Port)");
      for (int i = 0; i < invalidPortList.length; i++) {
         String testURL = validScheme + validAuthority + invalidPortList[i] + validPath;
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }

   public void testYourFourthPartition(){  
      String[] validPathList = {"","/","/path","/path/","/foo/bar" "/foo/bar/", "/1/2/3/4/" };
      String[] invalidPathList = {"/path/...test","badpath","////alsobadpath", "//oopspath"};
      UrlValidator urlVal = new UrlValidator();

      //TEST QUERY PARTITIONING: VALID (TRY URLS CONTAINING THE VALID TEST PATHS)
      System.out.println("\n\nTESTS: Running Fourth Partition Testing (Valid Path)");
      for (int i = 0; i < validPathList.length; i++) {
         String testURL = validScheme + validAuthority + validPort + validPathList[i];
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST QUERY PARTITIONING: INVALID (TRY URLS CONTAINING THE INVALID TEST PATHS)
      System.out.println("\n\nTESTS: Running Fourth Partition Testing (Invalid Path)");
      for (int i = 0; i < invalidPathList.length; i++) {
         String testURL = validScheme + validAuthority + validPort + invalidPathList[i];
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }

   public void testYourFifthPartition(){  
      String[] validQueryList = {"","?foo=bar","?state=oregon&best=true", "?foo+bar=foobar"};
      String[] invalidQueryList = {"/ ?s","?a=b=c","?d e f","???foo=bar"};
      UrlValidator urlVal = new UrlValidator();

      //TEST QUERY PARTITIONING: VALID (TRY URLS CONTAINING THE VALID TEST QUERIES)
      System.out.println("\n\nTESTS: Running Fifth Partition Testing (Valid Query)");
      for (int i = 0; i < validQueryList.length; i++) {
         String testURL = validScheme + validAuthority + validPort + validPath + validQueryList[i];
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }

      //TEST QUERY PARTITIONING: INVALID (TRY URLS CONTAINING THE INVALID TEST QUERIES)
      System.out.println("\n\nTESTS: Running Fifth Partition Testing (Invalid query)");
      for (int i = 0; i < invalidQueryList.length; i++) {
         String testURL = validScheme + validAuthority + validPort + validPath + invalidQueryList[i];
         System.out.println("TESTING: " + testURL);
         System.out.println(urlVal.isValid(testURL));
      }
      System.out.println("\n\n***********************\n\n");
   }



   public void testIsValid()
   {
	  //You can use this function for programming based testing

   }
   




}
