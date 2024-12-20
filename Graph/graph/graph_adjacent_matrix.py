# File name     : graph_adjacent_matrix.py
# Description   :
#
#
#


class GraphAdjacentMatrix:
    def __init__(self):
        self.vertices : list[int] = []
        self.adjacent_matrix : list[list[int]] = []

    def size(self):
        return len(self.vertices)

    def add_vertex(self, vertex_val):
        n = self.size()
        self.vertices.append(vertex_val)

        new_row : list[int] = [0] * n
        self.adjacent_matrix.append(new_row)
        for row in self.adjacent_matrix:
            row.append(0)

    def remove_vertex(self, vertex_index : int):
        if vertex_index >= self.size():
            raise IndexError()

        self.vertices.pop(vertex_index)
        self.adjacent_matrix.pop(vertex_index)
        for row in self.adjacent_matrix:
            row.pop(vertex_index)

    def add_edge(self, from_vertex_index : int, to_vertex_index : int):
        if (from_vertex_index < 0 or to_vertex_index < 0 or
            from_vertex_index >= self.size() or to_vertex_index >= self.size() or
            from_vertex_index == to_vertex_index):
            raise IndexError()

        self.adjacent_matrix[from_vertex_index][to_vertex_index] = 1
        self.adjacent_matrix[to_vertex_index][from_vertex_index] = 1

    def remove_edge(self, from_vertex_index : int, to_vertex_index : int):
        if (from_vertex_index < 0 or
            to_vertex_index < 0 or
            from_vertex_index >= self.size() or
            to_vertex_index >= self.size() or
            from_vertex_index == to_vertex_index):
            raise IndexError()

        self.adjacent_matrix[from_vertex_index][to_vertex_index] = 0
        self.adjacent_matrix[to_vertex_index][from_vertex_index] = 0

    def print(self):
        print("Graph vertex array = ", self.vertices)
        print("Graph adjacent matrix = ")
        for row in self.adjacent_matrix:
            print(row)



if __name__ == "__main__":
    graph = GraphAdjacentMatrix()

    graph.add_vertex(3)
    graph.add_vertex(105)
    graph.add_vertex(-306)
    graph.add_vertex(183)

    graph.add_edge(0, 2)
    graph.add_edge(2, 1)
    graph.add_edge(1, 3)

    graph.print()

    graph.add_vertex(48)
    graph.add_vertex(86)

    graph.add_edge(1, 4)
    graph.add_edge(5, 4)
    graph.print()

    graph.remove_vertex(4)
    graph.print()

    graph.add_vertex(1024)
    graph.remove_edge(4, 1)
    graph.print()