//http://codeforces.com/problemset/problem/7/B
import java.io.IOException;
import java.util.*;

public class Main {
    static int [] MEMORY;
    public static class Block {
        public int from;
        public  int end;
        public boolean isErase;
        public Block(int from, int end) {
            this.from = from;
            this.end = end;
            isErase = false;
        }
    }

    public static int lookForAvailablePosition(int size){
        for (int i = 0; i < MEMORY.length; i++) {
            if (MEMORY[i] == 0 && i + size <= MEMORY.length ) {
                boolean found = true;
                for (int j = i; j < i + size; j++) {
                    if (MEMORY[j] != 0) {
                        i = j;
                        found = false;
                        break;
                    }
                }
                if (found) return i;
            }
        }
        return -1;
    }

    public static void markAsAllocated(int begin, int size) {
        for (int i = begin; i < begin + size; i++) {
            MEMORY[i] = 1;
        }
    }

    public static void markAsFree(int begin, int size) {
        for (int i = begin; i < begin + size; i++) {
            MEMORY[i] = 0;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int m = scanner.nextInt();

        MEMORY = new int[m];
        Map<Integer, Block> allocatedBlocks = new HashMap<>();

        int numOfSuccessAlloc = 0;
        while (t >= 0) {
            String[] line = scanner.nextLine().split(" ");
            if (line[0].equalsIgnoreCase("alloc")) {
                int memToAlloc = Integer.parseInt(line[1]);
                int index = lookForAvailablePosition(memToAlloc);

                if (index == -1) {
                    System.out.println("NULL");
                } else {
                    numOfSuccessAlloc++;
                    System.out.println(numOfSuccessAlloc);
                    Block block = new Block(index, index + memToAlloc);
                    allocatedBlocks.put(numOfSuccessAlloc, block);
                    markAsAllocated(index, memToAlloc);
                }
            } else if (line[0].equalsIgnoreCase("erase")) {
                int blockToErase = Integer.parseInt(line[1]);

                Block blockToFree = allocatedBlocks.get(blockToErase);
                if (blockToFree == null) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                } else {
                    markAsFree(blockToFree.from, blockToFree.end - blockToFree.from);
                    allocatedBlocks.remove(blockToErase);
                }
            } else if (line[0].equalsIgnoreCase("defragment")) {
                List<Block> blocks = new ArrayList<>();
                for (Map.Entry<Integer, Block> entry : allocatedBlocks.entrySet()) {
                    blocks.add(entry.getValue());
                }
                Collections.sort(blocks, new Comparator<Block>() {
                    @Override
                    public int compare(Block block1, Block block2) {
                        return block1.from - block2.from;
                    }
                });

                int tmp = 0;
                for(Block block: blocks) {
                    int size = block.end - block.from;
                    block.from = tmp;
                    block.end = block.from + size;
                    markAsAllocated(tmp, size);
                    tmp = block.end;
                }
                markAsFree(tmp, MEMORY.length - tmp );

            }
            t--;
        }
    }
}