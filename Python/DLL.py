class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None  # Pointer to the previous node
        self.next = None  # Pointer to the next node

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        """Add a node at the end of the list"""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.prev = temp

    def prepend(self, data):
        """Add a node at the beginning of the list"""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def delete(self, data):
        """Delete a node with a specific value"""
        temp = self.head
        while temp and temp.data != data:
            temp = temp.next
        if not temp:
            return  # Data not found
        if temp.prev:
            temp.prev.next = temp.next
        if temp.next:
            temp.next.prev = temp.prev
        if temp == self.head:
            self.head = temp.next
        del temp  # Free memory

    def display(self):
        """Print the list from head to tail"""
        temp = self.head
        while temp:
            print(temp.data, end=" <-> ")
            temp = temp.next
        print("None")

# Example Usage
dll = DoublyLinkedList()
dll.append(10)
dll.append(20)
dll.append(30)
dll.prepend(5)
dll.display()  # Output: 5 <-> 10 <-> 20 <-> 30 <-> None
dll.delete(20)
dll.display()  # Output: 5 <-> 10 <-> 30 <-> None
