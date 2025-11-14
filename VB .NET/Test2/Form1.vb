Public Class Form1
    Private Sub ButtonSort_Click(sender As Object, e As EventArgs) Handles ButtonSort.Click
        Dim Array(4, 3) As String

        Array(0, 0) = "Laili"
        Array(0, 1) = "DSPD 2653"
        Array(0, 2) = "38"
        Array(0, 3) = "UTM JB"

        Array(1, 0) = "Yusri"
        Array(1, 1) = "DSPD 2453"
        Array(1, 2) = "38"
        Array(1, 3) = "UTM KL"

        Array(2, 0) = "Liew"
        Array(2, 1) = "DSPD 2653"
        Array(2, 2) = "39"
        Array(2, 3) = "UTM JB"

        Array(3, 0) = "Fattah"
        Array(3, 1) = "DDWD 2653"
        Array(3, 2) = "40"
        Array(3, 3) = "UTM JB"

        Array(4, 0) = "Shaqirah"
        Array(4, 1) = "DDWD 2453"
        Array(4, 2) = "38"
        Array(4, 3) = "UTM KL"

        Dim output As String = "Name: " & vbTab & "Code: " & vbTab & "Section: " & vbTab & "Location: " & vbCrLf
        For i As Integer = 0 To 4
            For j As Integer = 0 To 3
                output &= Array(i, j)
            Next
            output &= vbCrLf
        Next

        MessageBox.Show(output)
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Me.Hide()
        Form3.Show()
    End Sub
End Class
