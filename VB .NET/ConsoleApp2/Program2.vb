Imports System
' Question 2
Module Program2
    Sub Question2()
        Console.Write("Enter number of Elements: ")
        Dim n As Integer = Convert.ToInt32(Console.ReadLine())
        Dim arr(n - 1) As Integer

        Console.WriteLine("Enter the Elements: ")
        For i As Integer = 0 To n - 1
            arr(i) = Convert.ToInt32(Console.ReadLine())
        Next

        Dim Frequency As New Dictionary(Of Integer, Integer)
        For Each num In arr
            If Frequency.ContainsKey(num) Then
                Frequency(num) += 1
            Else
                Frequency(num) = 1
            End If
        Next
        Console.WriteLine("Frequencies: ")
        For Each kvp In Frequency
            Console.WriteLine("Frequency of " & kvp.Key & " = " & kvp.Value)
        Next

        Console.WriteLine("Press Enter to Continue...")
        Console.ReadLine()
    End Sub
End Module