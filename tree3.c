// http://www.nminoru.jp/~nminoru/programming/boehm-gc2.html
#include <stdio.h>
#include <gc.h>


typedef struct _Tree_tag {
  struct _Tree_tag* left;
  struct _Tree_tag* right;
} Tree;

Tree* generate_tree(int level) {
  if( level > 0 ){
    Tree* new_tree  = (Tree*)GC_malloc(sizeof(Tree));
    new_tree->left  = generate_tree(level-1);
    new_tree->right = generate_tree(level-1);
    return new_tree;
  } else {
    return (Tree*)0;
  }
}

int main(int argc, char** argv)
{
  int i;

  for(i = 0; i<100 ; i++){
    Tree* root ;
    printf("GC_get_heap_size: %ld\n",      GC_get_heap_size() );
    printf("GC_get_free_bytes: %ld\n",     GC_get_free_bytes() );
    printf("GC_get_bytes_since_gc: %ld\n", GC_get_bytes_since_gc() );
    printf("GC_get_total_bytes: %ld\n",    GC_get_total_bytes() );
    root = generate_tree(20);
    printf("GC counts: %d\n", GC_gc_no );
  }

  return 0;
}
