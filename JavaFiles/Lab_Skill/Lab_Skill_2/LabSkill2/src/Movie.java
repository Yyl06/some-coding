/*Lab Skill 2 - Question 5
Name        : Yong Yuan Lin
Date        : 21 August 2025*/


import java.util.Scanner;

public class Movie {
    private String title;
    private String director;
    private int rating;

    public Movie(){
        this.title = "Harry Potter";
        this.director = "David Heyman";
        this.rating = 5;
    }

    public Movie(String title, String director, int rating){
        this.title = title;
        this.director = director;
        this.rating = rating;
    }

    public static void main(String[] args) {
        Movie[] arrMovie = new Movie[5];
        for (int i = 0 ; i < arrMovie.length ; i++){
            arrMovie[i] = new Movie();
            Scanner sc = new Scanner(System.in);
            System.out.print("Please Enter Movie Title: ");
            String title = sc.nextLine();
            System.out.print("Please Enter Movie Director: ");
            String director = sc.nextLine();
            System.out.print("Enter rating: ");
            int rating = sc.nextInt();
            arrMovie[i].setMovie(title, director, rating);
        }
        arrMovie[4] = new Movie();
        arrMovie[4].setMovie("KL_Gangster_2", "Syamsul_Yusof", 8);

        for (Movie movie : arrMovie) {
            System.out.println(movie.toString());
        }
    }

    public void setMovie(String title, String director, int rating){
        this.title = title;
        this.director = director;
        this.rating = rating;
    }

    @Override
    public String toString(){
        return "Title: " + title + "\nDirector: " + director + "\nRating: " + rating;
    }
}
