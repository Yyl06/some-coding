Imports System
' Question 3
Module Program3
    Sub Question3()
        Console.Write("Enter Number of Elements: ")
        Dim n As Integer = Convert.ToInt32(Console.ReadLine())
        Dim arr(n - 1) As Integer

        Console.WriteLine("Enter the Elements: ")
        For i As Integer = 0 To n - 1
            arr(i) = Convert.ToInt32(Console.ReadLine())
        Next

        Console.WriteLine("Enter Number of Rotations: ")
        Dim r As Integer = Convert.ToInt32(Console.ReadLine())
        r = r Mod n

        Dim LeftRotation = arr.Skip(r).Concat(arr.Take(r)).ToArray()
        Dim RightRotation = arr.Skip(n - r).Concat(arr.Take((n - r))).ToArray()

        Console.WriteLine("Left Rotation (" & r & "): " & String.Join(" ", LeftRotation))
        Console.WriteLine("Right Rotation (" & r & "): " & String.Join(" ", RightRotation))

        Console.WriteLine("Press Enter to End.....")
        Console.ReadLine()
    End Sub
End Module