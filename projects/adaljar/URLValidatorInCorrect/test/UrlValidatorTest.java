

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
      String[] invalidSchemesList = {"http:/","3ht://","http/", "http:", "://"}; 
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
      String[] validAuthorityList = {"www.amazon.com","amazon.com","amazon.org","amazon.edu"};
      String[] invalidAuthorityList = {"www.gmail%.com","ccc.gmail.com",""," ","www.gmail"};
      UrlValidator urlVal = new UrlValidator();

      //TEST AUTHORITY PARTITIONING: VALOD (TRY URLS CONTAINING THE VALID TEST AUTHORITY)
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
       //You can use this function to implement your Second Partition testing    

   }

   public void testYourFourthPartition(){
       //You can use this function to implement your Second Partition testing    

   }

   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
