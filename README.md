# dimmerSwitch
Real world application. Dimmer switch adjusts the brightness of all lightbulbs associated with it. 

This probelm was given during an interview :

create two entities a dimmer switch and lightbulbs. The dimmer switch controls the amount of watts
being outputed by the bulb(the brightness of the bulbs). A dimmer switch can adjust the brightness
levels of multiple lightbulbs

// MIN_LEVEL = 5
// MAX_LEVEL = 15

// Dimmer | 5W | 10W | 20W
// 5      | 0  |  0  |  0
// 15     | 5  | 10  | 20
// 10     | 2.5|  5  | 10

The dimmer switch has a min of 5 and max of 15. If the dimmer is operating at min level which is 5
then the bulbs will have 0 output meaning the bulbs are turned off. If the dimmer is operating at
max level which is 15 then the associated lightbuls will be completely turned on and outputting 
maximum wattage.If the dimmer is operating at level 10 then we are getting the bulbs to operate at
half power, a 1000 watt bulb would only be outputting 500 watts. 

Implementation :

My code has two classes to represent the two entities, a lightbulb and a dimmer switch. The lightbulb 
class contains two values, wattValue and brightness. wattValue represents the maximum output of a 
lightbulb and brightness represents the actual output of the lightbulb. 

The dimmer switch class has a min and max value. It also has a dimmerValue which keeps track of the 
current dim level. An array is used to hold all lightbulb instances that are associated with said 
dimmer switch. This class has 3 methods size(), addLightBulb(lightbulb l), dimValue(int x). The
size method returns the amount of lightbulbs associated with dimmer switch. addLightBulb takes a
lightbulb instance and inserts it into an array. dimValue will take an int value and use the logic
presented above to figure out how bright the lightbulbs need to be. 
