/*Lab Skill 2 - Question 6
Name		: Yong Yuan Lin
Date		: 21 August 2025*/

import java.util.Scanner;

public class MUETCandidate {
    private String CandidateID;
    private double ListeningScore;
    private double ReadingScore;
    private double WritingScore;
    private double SpeakingScore;

    public MUETCandidate(){
        CandidateID = "1";
        ListeningScore = 1;
        ReadingScore = 1;
        WritingScore = 1;
        SpeakingScore = 1;  
    }

    public MUETCandidate(String CandidateID, double ListeningScore, double ReadingScore, double WritingScore, double SpeakingScore) {
        this.CandidateID = CandidateID;
        this.ListeningScore = ListeningScore;
        this.ReadingScore = ReadingScore;
        this.WritingScore = WritingScore;
        this.SpeakingScore = SpeakingScore;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        MUETCandidate[] candidates = new MUETCandidate[10];

        for (int i = 0; i < candidates.length; i++) {
            double ListeningScore = 0, ReadingScore = 0, WritingScore = 0, SpeakingScore = 0;

            while (true) {
                System.out.print("Enter Listening Score (1~45): ");
                ListeningScore = sc.nextDouble();
                if (ListeningScore >= 1 && ListeningScore <= 45){
                    break;
                }
                System.err.println("Please Enter a valid Number (1~45)");
            }

            while (true) {
                System.out.print("Enter Reading Score (1~120): ");
                ReadingScore = sc.nextDouble();
                if (ReadingScore >= 1 && ReadingScore <= 120){
                    break;
                }
                System.err.println("Please Enter a valid number (1~120)");
            }

            while (true) {
                System.out.print("Enter Writing Score (1~90): ");
                WritingScore = sc.nextDouble();
                if (WritingScore >= 1 && WritingScore <= 90){
                    break;
                }
                System.err.println("Please Enter a valid number (1~90)");
            }

            while (true) {
                System.out.print("Enter Speaking Score (1~45): ");
                SpeakingScore = sc.nextDouble();
                if (SpeakingScore >= 1 && SpeakingScore <= 45){
                    break;
                }
                System.err.println("Please Enter a valid number (1~45)");
            }

            candidates[i] = new MUETCandidate(String.valueOf(i + 1), ListeningScore, ReadingScore, WritingScore, SpeakingScore);
            System.out.println("Candidate " + String.valueOf(i + 1) + "'s Total Score: " + candidates[i].calculateTotalScore());
            System.out.println("Band Score: " + candidates[i].determineBandScore());
        }
        sc.close();
    }

    public double calculateTotalScore(){
        return ListeningScore + ReadingScore + WritingScore + SpeakingScore;
    }

    public int determineBandScore(){
        if(calculateTotalScore() >= 260 && calculateTotalScore() <= 300){
            return 6;
        }else if (calculateTotalScore() >= 220 && calculateTotalScore() <= 259){
            return 5;
        }else if(calculateTotalScore() >= 180 && calculateTotalScore() <= 219){
            return 4;
        }else if(calculateTotalScore() >= 140 && calculateTotalScore() <= 179){
            return 3;
        }else if(calculateTotalScore() >= 100 && calculateTotalScore() <= 139){
            return 2;
        }else{
            return 1;
        }
    }
}
