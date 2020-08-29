//Author: Christian Esperon
#include <iostream>
#include <vector>

using namespace std;

//instructor example:
// Dimmer switch, and 0+ lightbulbs

// MIN_LEVEL = 5
// MAX_LEVEL = 15

// Dimmer | 5W | 10W | 20W
// 5      | 0  |  0  |  0
// 15     | 5  | 10  | 20
// 10     | 2.5|  5  | 10

class lightBulb {
  
  public:
    
    //bulb brightness level represents how bright the bulb gets according to dimmer value
    int brightness;
    //watt value is the max wattage of lightbulb 
    int wattValue;
    
    //lightbulb constructor
    lightBulb(int watts){
      
        wattValue = watts;
      
    }
};

class Dimmer {
  
  public:
    
    //min and max level of dimmer
    int MIN_LEVEL = 5;
    int MAX_LEVEL = 15;
    
    //dimmer value initialized to 0
    int dimmerValue = 0;
    
    //array to hold all lightbulbs that are associated with dimmer
    vector<lightBulb> lightBulbs;
    
    //set dim value to all associated light bulbs
    void dimValue(int x) {
      
      dimmerValue = x;
      
      //if there are no lightbulbs associated with dimmer then relay that message to user    
      if(lightBulbs.size() == 0){
        
          cout<< "there are no lightbulbs associated with dim switch"<<endl;
        
      }
      else{
        
          //if there are lightbulbs associated with dimmer then iterate through list of bulbs
          for(int i = 0; i<lightBulbs.size(); i++){
          
              //if dim level is at max then brightness level of bulb reaches max wattage
              if(dimmerValue == MAX_LEVEL){
                lightBulbs[i].brightness = lightBulbs[i].wattValue;  
              }
              //if dim level is at min then brightness level of bulb is 0 or off
              if(dimmerValue == MIN_LEVEL){
                lightBulbs[i].brightness = 0;
              }
              if(dimmerValue > MIN_LEVEL && dimmerValue < MAX_LEVEL){
                
                //if dim level is between max and min then we must adjust bulb brightness accordingly
                //equation behind logic:
                //dim level = 10, bulb wattValue = 1000
                int dimDif = dimmerValue - MIN_LEVEL;   //dimDif = 10 - 5  = 5
                float dimPercentage = float(dimDif)/float(MAX_LEVEL - MIN_LEVEL);   //dimPercentage = 5/10=1/2
                float newBrightness = dimPercentage * lightBulbs[i].wattValue;      //newBrightness = 1/2*1000
                lightBulbs[i].brightness = int(newBrightness);    //set bulb brightness to newBrightness
                
              }
              
              cout<< lightBulbs[i].wattValue << " watt bulb is at " << lightBulbs[i].brightness << " brightness"<<endl;
          }
        }
      
    }
    
    //add a lightbulb to be controlled by the dimmer instance
    void addLightBulb(lightBulb newBulb){
      
      lightBulbs.push_back(newBulb);
      
    }
    
    //return the number of lightbulbs associated with dimmer
    int size(){
      
      return lightBulbs.size();
      
    }

};

int main() {
	
  //create a dimmer instance
  Dimmer newDimmer = Dimmer();
  
  //create a lightbulb instance
  lightBulb bulb1 = lightBulb(1000);
  lightBulb bulb2 = lightBulb(4000);
  lightBulb bulb3 = lightBulb(200);
  lightBulb bulb4 = lightBulb(15000);
  
  //add lightbulbs to dimmer
  newDimmer.addLightBulb(bulb1);
  newDimmer.addLightBulb(bulb2);
  newDimmer.addLightBulb(bulb3);
  newDimmer.addLightBulb(bulb4);
  
  //check how many lightbulbs are associated with dimmer
  cout<<"Number of lightbulbs: "<<newDimmer.size()<<endl;
  
  //change the dim value of all the lightbulbs associated with dimmer
  newDimmer.dimValue(10);
  
	return 0;
}
