/* Without seeing implementation */

class GraphNode {
    constructor (val) {
        this.value = val;
    }
}

// Adjacency matrix
let adjMat = [
    [0, 3, Infinity, 7],
    [8, 0, 2, Infinity],
    [5, Infinity, 0, 1],
    [2, Infinity, Infinity, 0]
];

let a = new GraphNode(0);
let b = new GraphNode(1);
let c = new GraphNode(2);
let d = new GraphNode(3);

let vertices = [a, b, c, d];

function FloydWarshall (adjMat, vertices) {
    let A = adjMat; // creating a copy rather than reference

    for (let i = 0; i < vertices.length; i++) {
        let rowIndex = vertices[i].value,
            colIndex = vertices[i].value;

        for (let m = 0; m < A.length; m++) {
            for (let n = 0; n < A[m].length; n++) {
                A[m][n] = Math.min(A[m][n], (A[m][colIndex] + A[rowIndex][n]));
            }
        }
    }

    console.log(A);
}

FloydWarshall(adjMat, vertices);
