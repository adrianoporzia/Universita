import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        Casa casa1 = new Casa(7, 3, 16);
        Casa casa2 = new Casa(6, 8, 10);
        Casa casa3 = new Casa(7, 9, 4);
        Casa casa4 = new Casa(8, 22, 2);
        Casa casa5 = new Casa(9, 12, 5);
        Casa casa6 = new Casa(20, 8, 7);

        ArrayList<Integer> arrayRed = new ArrayList<Integer>();     //costi rossi
        ArrayList<Integer> arrayGreen = new ArrayList<Integer>();   //costi verdi
        ArrayList<Integer> arrayBlue = new ArrayList<Integer>();    //costi blu

        ArrayList<Casa> caseList = new ArrayList<Casa>();           //tutte le case

        caseList.add(casa1);                                        //aggiungo le case in  un array
        caseList.add(casa2);                                        // cosi con un for each prendo i singoli
        caseList.add(casa3);                                        //attributi
        caseList.add(casa4);
        caseList.add(casa5);
        caseList.add(casa6);



        for(Casa i : caseList){                                     //creo i tre array per calcolare OPT
            arrayRed.add(i.red);
            arrayGreen.add(i.green);
            arrayBlue.add(i.blue);
        }

        int min = Math.min(Math.min(arrayRed.get(0), arrayGreen.get(0)), arrayBlue.get(0));

        int len = arrayRed.size();
        for(int i = 1; i < len; i++){
            arrayRed.set(i, arrayRed.get(i) + Math.min(arrayGreen.get(i - 1), arrayBlue.get(i - 1)));
            arrayGreen.set(i, arrayGreen.get(i) + Math.min(arrayRed.get(i - 1), arrayBlue.get(i - 1)));
            arrayBlue.set(i, arrayBlue.get(i) + Math.min(arrayGreen.get(i - 1), arrayRed.get(i - 1)));

        }
        System.out.println(Math.min(Math.min(arrayRed.get(len - 1), arrayGreen.get(len - 1)), arrayBlue.get(len - 1)));


    }
}