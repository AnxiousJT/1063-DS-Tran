```
/*
 @Homework: Homework-3
 @Author: Jackson Tran
 @Description:The majority of this code was created during class, but the
 print method didn't work properly when called to print a full array. The
 homework assignment is to fix the print method to work with any content
 in the array
 @Course: 1063 Data Structures
 @Semester: Spring 2017
 @Date: 02-28-2017
*/
/*
 @FunctionName: Print
 @Description: To allow print to work with the full array
 when called, I used an or statement with a variable that I would change
 so that the method would work without going through an infinite loop
 @Params: None
 @Returns: None
 */
	void Print() {
		int Index = Front;
		int fullCheck = 0;
		while (Index != Rear || fullCheck == 0) {
			cout << Q[Index] << " ";
			Index = ((Index + 1) % (ArraySize));
			fullCheck++;
		}
		cout << endl;
	}
};
```
