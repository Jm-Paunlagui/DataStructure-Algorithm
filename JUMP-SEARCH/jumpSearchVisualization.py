# importing libraries 

# https://phoenixnap.com/kb/install-pip-windows
# https://pypi.org/project/PyQt5/
from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui 
from PyQt5.QtGui import *
from PyQt5.QtCore import *
import sys 


class Window(QMainWindow): 

	# list of numbers 
	number = [0,.5,.75,2,5,8,9,10] 

	def __init__(self): 
		super().__init__() 

		# setting title 
		self.setWindowTitle("Jump search ") 

		# setting geometry 
		self.setGeometry(100, 100, 600, 400) 

		# calling method 
		self.UiComponents() 

		# showing all the widgets 
		self.show() 

	# method for widgets 
	def UiComponents(self): 

		# start flag 
		self.start = False

		# linear search and binary search flag 
		self.linear = False
		self.jump = True

		# list to hold labels 
		self.label_list = [] 

		# desired value 
		self.desired = 9

		# step size 
		self.step = 2

		# counter to calculate index 
		self.counter = 0

		# index used to jumping 
		self.index = 0

		# local index for linear search 
		self.linear_index = 0

		# local counter 
		c = 0

		# iterating list of numbers 
		for i in self.number: 

			# creating label for each number 
			label = QLabel(str(i), self) 

			# adding background color and border 
			label.setStyleSheet("border : 1px solid black; background : white;") 

			# aligning the text 
			label.setAlignment(Qt.AlignTop) 

			# setting geometry using local counter 
			# first parameter is distance from left and second is distance from top 
			# third is width and forth is height 
			label.setGeometry(50 + c * 30, 50, 20, i * 10 + 10) 

			# adding label to the label list 
			self.label_list.append(label) 

			# incrementing local counter 
			c = c + 1


		# creating push button to start the search 
		self.search_button = QPushButton("Start Search", self) 

		# setting geometry of the button 
		self.search_button.setGeometry(100, 270, 100, 30) 

		# adding action to the search button 
		self.search_button.clicked.connect(self.search_action) 

		# creating push button to pause the search 
		pause_button = QPushButton("Pause", self) 

		# setting geometry of the button 
		pause_button.setGeometry(100, 320, 100, 30) 

		# adding action to the search button 
		pause_button.clicked.connect(self.pause_action) 

		# creating label to show the result 
		self.result = QLabel("To search : " + str(self.desired), self) 

		# setting geometry 
		self.result.setGeometry(350, 280, 200, 40) 

		# setting style sheet 
		self.result.setStyleSheet("border : 3px solid black;") 

		# adding font 
		self.result.setFont(QFont('Times', 10)) 

		# setting alignment 
		self.result.setAlignment(Qt.AlignCenter) 

		# creating a timer object 
		timer = QTimer(self) 

		# adding action to timer 
		timer.timeout.connect(self.showTime) 

		# update the timer every 300 millisecond 
		timer.start(500) 

	# method called by timer 
	def showTime(self): 


		# checking if flag is true 
		if self.start: 
			# implementing jump search 

			# implementing jumping gap 
			if self.jump: 

				# checking if jump index is greater then the length of list 
				if self.counter * self.step >= len(self.number): 

					# setting linear indes 
					self.linear_index = self.index - self.step 

					# setting counter value 
					self.counter = 0

					# making jumping false 
					self.jump = False

					# making linear flag true 
					self.linear = True

				# updating the index 
				self.index = self.step * self.counter 

				# checking if desired value get found 
				if self.number[self.index] == self.desired: 

					# stopping the search 
					self.start = False
					self.jump = False

					# show result in the result label 
					self.result.setText("Found at index : " + str(self.index)) 

					# making the label color green 
					self.label_list[self.index].setStyleSheet("border : 2px solid green;"
															"background-color : lightgreen;") 

				# if not found 
				else: 
					# making the label color grey 
					self.label_list[self.index].setStyleSheet("border : 1px solid black;"
															"background-color : grey;") 

				# if index value is greater 
				if self.number[self.index] > self.desired: 

					# setting linear index 
					self.linear_index = self.index - self.step 
					# updating the counter value 
					self.counter = 0
					# making linear flag True 
					self.linear = True

					# stopping the jumping 
					self.jump = False

				# updating the counter 
				self.counter += 1

				# updating the index 
				self.index = self.step * self.counter 

				# if index exceeds the limit 
				if self.counter * self.step >= len(self.number): 
					# updating the linear search 
					self.linear_index = self.index - self.step 
					
					# updating the counter value 
					self.counter = 0
					
					# stopping the jumping 
					self.jump = False
					
					# starting linear search 
					self.linear = True

			# linear search 
			if self.linear: 
				# if counter become equal to steop 
				if self.counter == self.step: 
					# stop the search 
					self.start = False
					# show result i.e not found 
					self.result.setText("Not found") 

				# if linear index is negative 
				if self.linear_index < 0: 
					# making it zero 
					self.linear_index = 0

				# checking value if found 
				if self.number[self.counter + self.linear_index] == self.desired: 
					# stop the search 
					self.linear = False
					self.start = False
					# show result 
					self.result.setText("Found at index : " + str(self.counter +
																self.linear_index)) 
					# make label color green 
					self.label_list[self.counter + self.linear_index].setStyleSheet( 
														"border : 2px solid green;"
														"background-color : lightgreen;") 

				# if not found 
				else: 
					# make label color grey 
					self.label_list[self.counter + self.linear_index].setStyleSheet( 
														"border : 1px solid black;"
														" background-color : grey;") 

				# updating the counter 
				self.counter += 1


	# method called by search button 
	def search_action(self): 

		# making flag true 
		self.start = True

		# showing text in result label 
		self.result.setText("Started searching...") 

	# method called by pause button 
	def pause_action(self): 

		# making flag false 
		self.start = False

		# showing text in result label 
		self.result.setText("Paused") 


# create pyqt5 app 
App = QApplication(sys.argv) 

# create the instance of our Window 
window = Window() 

# start the app 
sys.exit(App.exec()) 
