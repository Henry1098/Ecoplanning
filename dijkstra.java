int[][] matrix = // you adjacency matrix
  int initialVertex = // the starting vertex.
 
  public int[] getSolution() {
 
    LinkedList used = new LinkedList();
    used.add(new Integer(initialVertex));
 
    LinkedList unused = new LinkedList();
    for (int i = 0; i < matrix.length; i++) {
      if (i != initialVertex)
        unused.add(new Integer(i));
    }
 
    solution = new int[matrix.length];
    for (int i = 0; i < solution.length; i++)
      solution[i] = matrix[initialVertex][i];
 
  
    Integer vertex;
    Iterator i;
    int value;
    while (unused.size() > 0) {
      vertex = (Integer)unused.removeFirst();
      used.add(vertex);
 
      i = unused.iterator();
      while (i.hasNext()) {
        value = ((Integer)i.next()).intValue();
        solution[value] = (int)Math.max(solution[value], 
                                        (solution[vertex.intValue()] + 
                                        matrix[vertex.intValue()][value]));
 
      }      
 
    }
 
 
    return solution;    
 
  }
