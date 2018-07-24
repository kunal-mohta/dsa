class StackNode {
  constructor (val) {
    this.value = val;
    this.next = null;
  }
};

class Stack {
  constructor () {
    this.head = null;
  }

  push (val) {
    if (this.head == null) {
      this.head = new StackNode(val);
    }
    else {
      let newNode = new StackNode(val);
      newNode.next = this.head;
      this.head = newNode;
    }
  }

  pop () {
    if (this.head == null) {
      console.log('The stack is empty');
      return false;
    }
    else {
      let returnVal = this.head.value;
      this.head = this.head.next;
      return returnVal;
    }
  }

  print () {
    let temp = this.head;

    while (temp) {
      console.log(temp.value);
      temp = temp.next;
    }
  }
}

let stack1 = new Stack();

stack1.push(1);
stack1.push(2);
stack1.print();
stack1.pop();
stack1.print();