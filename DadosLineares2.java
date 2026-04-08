public class DadosLineares2 {

    class Celula{
        int elemento;
        Celula prox;

        public Celula(){
            this.elemento = 0;
            this.prox = null;
        }
        public Celula(int elemento){
            this.elemento = elemento;
            this.prox = null;
        }
    }

    class Pilha{ //LIFO
        Celula topo;

        public Pilha(){
            this.topo = null;
        }

        void inserir(int x){
            Celula tmp = new Celula(x);
            tmp.prox = topo;
            topo = tmp;
            tmp = null;
        }

        int remover(){
            if(topo == null){
                return -1;
            }
            int resp = topo.elemento;
            Celula tmp = topo;
            topo = topo.prox;
            tmp.prox = null;
            tmp = null;
            return resp;
        }
    }

    class Fila{ //FIFO
        Celula primeiro;
        Celula ultimo;

        public Fila(){
            primeiro = new Celula();
            ultimo = primeiro;
        }

        void inserir(int x){
            ultimo.prox = new Celula(x);
            ultimo = ultimo.prox;
        }

        int remover(){
            if(primeiro == ultimo){
                return -1;
            }
            Celula tmp = primeiro;
            primeiro = primeiro.prox;
            int resp = primeiro.elemento;
            tmp.prox = null;
            tmp = null;
            return  resp;
        }
    }

    class Lista{
        Celula primeiro;
        Celula ultimo;

        public Lista(){
            primeiro = new Celula();
            ultimo = primeiro;
        }

        void inserirInicio(int x){
            Celula tmp = new Celula(x);
            tmp.prox = primeiro.prox;
            primeiro.prox = tmp;
            if(primeiro == ultimo){
                ultimo = tmp;
            }
            tmp = null;
        }

        void inserirFim(int x){
            ultimo.prox = new Celula(x);
            ultimo = ultimo.prox;
        }

        int removerInicio(){
            if(primeiro == ultimo){
                return -1;
            }
            Celula tmp = primeiro;
            primeiro = primeiro.prox;
            int resp = primeiro.elemento;
            tmp.prox = null;
            tmp = null;
            return  resp;
        }

        int removerFim(){
            if(primeiro == ultimo){
                return -1;
            }
            Celula i;
            for(i = primeiro; i.prox != ultimo; i = i.prox);
            int resp = ultimo.elemento;
            ultimo = i;
            ultimo.prox = i = null;
            return resp;
        }
    }
}

