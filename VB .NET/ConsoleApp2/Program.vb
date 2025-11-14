Imports System
' Question 1
Module Program
    Sub Question1()
        ' 1)a)
        Console.Write("Enter Number of Elements: ")
        Dim n As Integer = Convert.ToInt32(Console.ReadLine())
        Dim arr(n - 1) As Integer

        Console.WriteLine("Enter the Elements: ")
        For i As Integer = 0 To n - 1
            arr(i) = Convert.ToInt32(Console.ReadLine())
        Next

        Dim EvenCount As Integer = 0, OddCount As Integer = 0
        For Each num In arr
            If num Mod 2 = 0 Then
                EvenCount += 1
            Else
                OddCount += 1
            End If
        Next
        Console.WriteLine("Even Count: " & EvenCount)
        Console.WriteLine("Odd Count: " & OddCount)

        ' 1)b)
        Dim frequency As New Dictionary(Of Integer, Integer)
        For Each num In arr
            If frequency.ContainsKey(num) Then
                frequency(num) += 1
            Else
                frequency(num) = 1
            End If
        Next
        Console.WriteLine("Duplicate Elements: ")
        For Each kvp In frequency
            If kvp.Value > 1 Then
                Console.WriteLine(kvp.Key & "appears " & kvp.Value & " times")
            End If
        Next

        ' 1)c)
        Array.Sort(arr)
        Console.WriteLine("Asending: " & String.Join(" ", arr))
        Array.Reverse(arr)
        Console.WriteLine("Desending: " & String.Join(" ", arr))

        ' 1)d)
        Dim even = arr.Where(Function(x) x Mod 2 = 0).ToArray()
        Dim odd = arr.Where(Function(x) x Mod 2 <> 0).ToArray()
        Console.WriteLine("Even Numbers: " & String.Join(" ", even))
        Console.WriteLine("Odd Numbers: " & String.Join(" ", odd))

        Console.WriteLine("Press Enter to Continue...")
        Console.ReadLine()
    End Sub
End Module