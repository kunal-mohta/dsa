class QueueNode {
  constructor (val) {
    this.value = val;
    this.next = null;
    this.prev = null;
  }
}

class Queue {
  constructor () {
    this.head = null;
    this.tail = null;
  }

  enqueue (val) {
    if (this.head == null) {
      this.head = new QueueNode(val);
      this.tail = this.head;
    }
    else {
      let newNode = new QueueNode(val);
      this.head.prev = newNode;
      newNode.next = this.head;
      this.head = newNode;
    }
  }

  dequeue () {
    if (this.head = null) {
      console.log('The queue is empty');
      return false;
    }
    else {
      let returnVal = this.tail.value;
      this.tail = this.tail.prev;
      return returnVal;
    }
  }

  print () {
    let temp = this.tail;

    while (temp) {
      console.log(temp.value);
      temp = temp.prev;
    }
  }
}

let q = new Queue();

q.enqueue(1);
q.enqueue(2);
q.print();
q.dequeue();
q.print();