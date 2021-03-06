#include <linux/module.h>
MODULE_AUTHOR("EL HLAFI Mohamed");
MODULE_DESCRIPTION("This is an exemple of a  kernel  module ");
static int param_entier=0;
module_param(param_entier,int,0644);

MODULE_PARM_DESC(param_entier,"une valeure entiere ");

static char* param_chain="-par defaut-";
module_param(param_chain,charp,0644);
MODULE_PARM_DESC(param_chain,"une chaine de charactere ");

static int param_table[8];
static int nb_elements;
module_param_array(param_table,int,&nb_elements,0644);

MODULE_PARM_DESC(param_table,"tableau ");

static int __init exemple_module_init(void){
  int i ;
  printk(KERN_INFO "%s :(Chargement)Entier =%d\n",THIS_MODULE->name,param_entier);

  printk(KERN_INFO "%s :(Chargement)Chain =%s\n",THIS_MODULE->name,param_chain);

  printk(KERN_INFO "%s :(Chargement)nombre_d'elements =%d\n",THIS_MODULE->name,nb_elements);

  printk(KERN_INFO "%s :(Chargement)array_table:\n",THIS_MODULE->name);
  for(i=0;i<nb_elements;i++){
    printk("table[%d]=%d\n",i,param_table[i]);
  }
  return 0;
}
void __exit exemple_module_exit(void){

  int i ;
  printk(KERN_INFO "%s :(Dechargement)Entier =%d\n",THIS_MODULE->name,param_entier);

  printk(KERN_INFO "%s :(Dechargement)Chain =%s\n",THIS_MODULE->name,param_chain);

  printk(KERN_INFO "%s :(Dchargement)nombre_d'elements =%d\n",THIS_MODULE->name,nb_elements);

  printk(KERN_INFO "%s :(Dechargement)array_table \n",THIS_MODULE->name);
  for(i=0;i<nb_elements;i++){
      printk("table[%d]=%d\n",i,param_table[i]);
  }
}
module_init(exemple_module_init);
module_exit(exemple_module_exit);
MODULE_LICENSE("GPL");
