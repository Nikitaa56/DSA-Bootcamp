class LiftManagementSystem:
    def __init__(self, total_floors):
        self.current_floor = 0  # Lift starts at the ground floor
        self.total_floors = total_floors
        self.up_list = []  # List to store upward requests
        self.down_list = []  # List to store downward requests
        self.direction = "up"  # Initially, lift is moving upwards

    def request_lift(self, floor):
        if 0 <= floor < self.total_floors:
            if floor > self.current_floor:
                if floor not in self.up_list:
                    self.up_list.append(floor)  # Add to upward list if it’s an upward request
                    print(f"Lift requested at floor {floor} (up)")
            elif floor < self.current_floor:
                if floor not in self.down_list:
                    self.down_list.append(floor)  # Add to downward list if it’s a downward request
                    print(f"Lift requested at floor {floor} (down)")
            else:
                print(f"Lift is already on floor {floor}")
        else:
            print(f"Invalid floor number: {floor}")

    def move_lift(self):
        # Sort the requests to serve them in a sequential manner
        self.up_list.sort()  # Sort in ascending order
        self.down_list.sort(reverse=True)  # Sort in descending order
        
        if self.direction == "up":
            self.serve_upward_requests()
            if self.down_list:  # If there are downward requests pending
                self.direction = "down"
                self.serve_downward_requests()
        elif self.direction == "down":
            self.serve_downward_requests()
            if self.up_list:  # If there are upward requests pending
                self.direction = "up"
                self.serve_upward_requests()

    def serve_upward_requests(self):
        while self.up_list:
            next_floor = self.up_list.pop(0)  # Get the next upward request (FIFO)
            self.go_to_floor(next_floor)
        print("No more upward requests.")

    def serve_downward_requests(self):
        while self.down_list:
            next_floor = self.down_list.pop(0)  # Get the next downward request (FIFO)
            self.go_to_floor(next_floor)
        print("No more downward requests.")

    def go_to_floor(self, floor):
        print(f"Moving lift from floor {self.current_floor} to floor {floor}...")
        self.current_floor = floor
        print(f"Lift has arrived at floor {floor}")

# Function to take input from the user
def main():
    total_floors = int(input("Enter the total number of floors in the building: "))
    lift_system = LiftManagementSystem(total_floors)
    
    while True:
        user_input = input("Enter a floor number to request the lift (or type 'done' to exit): ")
        if user_input.lower() == "done":
            break
        try:
            floor = int(user_input)
            lift_system.request_lift(floor)
        except ValueError:
            print("Please enter a valid number or 'done' to stop.")

    # Process the requests after the user is done
    lift_system.move_lift()

if __name__ == "__main__":
    main()
