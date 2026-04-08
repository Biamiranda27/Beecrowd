class DadosLineares{

class Celula {
	public int elemento; 
	public Celula prox; 

	public Celula() {
		this.elemento = 0;
        this.prox = null;
	}
	public Celula(int elemento) {
      this.elemento = elemento;
      this.prox = null;
	}
}

public class Fila { //First In First Out
	private Celula primeiro;
	private Celula ultimo;

	public Fila() {
		primeiro = new Celula();
		ultimo = primeiro;
	}

	public void inserir(int x) { //enqueue
		ultimo.prox = new Celula(x);
		ultimo = ultimo.prox;
	}

	public int remover() throws Exception { //dequeue
		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover!");
		}
      Celula tmp = primeiro;
		primeiro = primeiro.prox;
		int resp = primeiro.elemento;
      tmp.prox = null;
      tmp = null;
		return resp;
	}

	public void mostrar() {
		System.out.print("[ ");
		for(Celula i = primeiro.prox; i != null; i = i.prox) {
			System.out.print(i.elemento + " ");
		}
		
		System.out.println("] ");
	}
}


public class Pilha {
	private Celula topo;

	public Pilha() {
		topo = null;
	}

	public void inserir(int x) { //push
		Celula tmp = new Celula(x);
		tmp.prox = topo;
		topo = tmp;
		tmp = null;
	}

	public int remover() throws Exception { //pop
		if (topo == null) {
			throw new Exception("Erro ao remover!");
		}
		int resp = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
		return resp;
	}

	public void mostrar() {
		System.out.print("[ ");
		for (Celula i = topo; i != null; i = i.prox) {
			System.out.print(i.elemento + " ");
		}
		System.out.println("] ");
	}

	public int getSoma() {
		return getSoma(topo);
	}

	private int getSoma(Celula i) {
		int resp = 0;
		if (i != null) {
			resp += i.elemento + getSoma(i.prox);
		}
		return resp;
	}

	public int getMax() {
		int max = topo.elemento;
		for (Celula i = topo.prox; i != null; i = i.prox) {
			if (i.elemento > max)
				max = i.elemento;
		}
		return max;
	}


}


class Lista {
	private Celula primeiro;
	private Celula ultimo;

	public Lista() {
		primeiro = new Celula();
		ultimo = primeiro;
	}

	public void inserirInicio(int x) {
		Celula tmp = new Celula(x);
      tmp.prox = primeiro.prox;
		primeiro.prox = tmp;
		if (primeiro == ultimo) {                 
			ultimo = tmp;
		}
      tmp = null;
	}

	public void inserirFim(int x) {
		ultimo.prox = new Celula(x);
		ultimo = ultimo.prox;
	}

    public void inserirPos(int x, int pos) throws Exception {
      int tamanho = tamanho();

      if(pos < 0 || pos > tamanho){
			throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
      } else if (pos == 0){
         inserirInicio(x);
      } else if (pos == tamanho){
         inserirFim(x);
      } else {
         Celula i = primeiro;
         for(int j = 0; j < pos; j++, i = i.prox);
         Celula tmp = new Celula(x);
         tmp.prox = i.prox;
         i.prox = tmp;
         tmp = i = null;
      }
   }

	public int removerInicio() throws Exception {
		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover (vazia)!");
		}
      Celula tmp = primeiro;
		primeiro = primeiro.prox;
		int resp = primeiro.elemento;
      tmp.prox = null;
      tmp = null;
		return resp;
	}

	public int removerFim() throws Exception {
		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover (vazia)!");
		} 
      Celula i;
      for(i = primeiro; i.prox != ultimo; i = i.prox);

      int resp = ultimo.elemento; 
      ultimo = i; 
      i = ultimo.prox = null;
      
		return resp;
	}

	public int removerPos(int pos) throws Exception {
      int resp;
      int tamanho = tamanho();
		if (primeiro == ultimo){
			throw new Exception("Erro ao remover (vazia)!");
      } else if(pos < 0 || pos >= tamanho){
			throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
      } else if (pos == 0){
         resp = removerInicio();
      } else if (pos == tamanho - 1){
         resp = removerFim();
      } else {
         Celula i = primeiro;
         for(int j = 0; j < pos; j++, i = i.prox);
         Celula tmp = i.prox;
         resp = tmp.elemento;
         i.prox = tmp.prox;
         tmp.prox = null;
         i = tmp = null;
      }
		return resp;
	}

	public void mostrar() {
		System.out.print("[ ");
		for (Celula i = primeiro.prox; i != null; i = i.prox) {
			System.out.print(i.elemento + " ");
		}
		System.out.println("] ");
	}

	public boolean pesquisar(int x) {
		boolean resp = false;
		for (Celula i = primeiro.prox; i != null; i = i.prox) {
         if(i.elemento == x){
            resp = true;
            i = ultimo;
         }
		}
		return resp;
	}

   public int tamanho() {
      int tamanho = 0; 
      for(Celula i = primeiro; i != ultimo; i = i.prox, tamanho++);
      return tamanho;
   }
}


class FilaCircular {
    private int[] fila;
    private int primeiro;
    private int ultimo;
    private int tamanho;
    private int capacidade;

    public FilaCircular(int capacidade) {
        this.capacidade = capacidade;
        fila = new int[capacidade];
        primeiro = 0;
        ultimo = -1;
        tamanho = 0;
    }

    public boolean isEmpty() {
        return tamanho == 0;
    }

    public boolean isFull() {
        return tamanho == capacidade;
    }

    public void inserir(int x) {
        if (isFull()) {
            System.out.println("Fila cheia!");
            return;
        }

        ultimo = (ultimo + 1) % capacidade;
        fila[ultimo] = x;
        tamanho++;
    }

    public int remover() {
        if (isEmpty()) {
            System.out.println("Fila vazia!");
            return -1;
        }

        int valor = fila[primeiro];
        primeiro = (primeiro + 1) % capacidade;
        tamanho--;

        return valor;
    }

    public int front() {
        if (isEmpty()) {
            System.out.println("Fila vazia!");
            return -1;
        }

        return fila[primeiro];
    }

    public void mostrar() {
        if (isEmpty()) {
            System.out.println("Fila vazia!");
            return;
        }

        int i = primeiro;
        for (int cont = 0; cont < tamanho; cont++) {
            System.out.print(fila[i] + " ");
            i = (i + 1) % capacidade;
        }
        System.out.println();
    }
}
}