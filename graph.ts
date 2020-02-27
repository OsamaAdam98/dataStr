class GraphNode {
  private val: number;
  private visited: boolean;
  private neighbours: Set<GraphNode>;

  constructor(val: number) {
    this.val = val;
    this.visited = false;
    this.neighbours = new Set();
  }

  get getVal() {
    this.setVisited();
    return this.val;
  }

  get isVisited() {
    return this.visited;
  }

  get getNeighbours() {
    return this.neighbours;
  }

  setVal(val: number) {
    this.val = val;
  }

  addNeighbour(neighbours: GraphNode[]) {
    neighbours.forEach((neighbour) => {
      this.neighbours.add(neighbour);
      if (!neighbour.getNeighbours.has(this)) neighbour.addNeighbour([this]);
    });
  }

  removeNeighbour(neighbour: GraphNode) {
    this.neighbours.delete(neighbour);
    if (neighbour.getNeighbours.has(this)) neighbour.removeNeighbour(this);
  }

  setVisited() {
    this.visited = true;
  }

  clearVisited() {
    this.visited = false;
  }
}

const graphNode1 = new GraphNode(1);
const graphNode2 = new GraphNode(2);
const graphNode3 = new GraphNode(3);
const graphNode4 = new GraphNode(4);
const graphNode5 = new GraphNode(5);

graphNode1.addNeighbour([graphNode2, graphNode3]);
graphNode2.addNeighbour([graphNode4]);
graphNode3.addNeighbour([graphNode5]);

const depthRecursion = (graphNode: GraphNode) => {
  graphNode.getNeighbours.forEach((neighbour) => {
    if (!neighbour.isVisited) {
      console.log(`${neighbour.getVal} is ${graphNode.getVal}'s neighbour.`);
      depthRecursion(neighbour);
    }
  });
};

const depthPrint = (entry: GraphNode) => {
  console.log(`${entry.getVal} is root`);
  depthRecursion(entry);
};

const breadthPrint = (entry: GraphNode) => {
  const neighboursQueue: Set<GraphNode> = new Set();
  console.log(`${entry.getVal} is root.`);
  entry.getNeighbours.forEach((neighbour) => {
    if (!neighbour.isVisited) {
      console.log(`${neighbour.getVal} is ${entry.getVal}'s neighbour.`);
      neighboursQueue.add(neighbour);
    }
  });
  neighboursQueue.forEach((node) => {
    node.getNeighbours.forEach((neighbour) => {
      if (!neighbour.isVisited) {
        console.log(`${neighbour.getVal} is ${node.getVal}'s neighbour.`);
        neighboursQueue.add(neighbour);
      }
    });
    neighboursQueue.delete(node);
  });
};

// depthPrint(graphNode1);
breadthPrint(graphNode1);
