Imports System
Public Class Form1
        Private Sub btnClickMe_Click(sender As Object, e As EventArgs) Handles btnClickMe.Click
        Dim members As String = "Group Members: " & vbCrLf & vbCrLf &
                "1. Yong Yuan Lin - A24DW0325" & vbCrLf &
                "2. Marcus Lai Wei Ze - A24DW283" & vbCrLf &
                "3. Chung Wei Kit - A24DW0132" & vbCrLf &
                "4. Tiong Yong Hern - A24DW0106"

        MessageBox.Show(members, "Group Info", MessageBoxButtons.OK, MessageBoxIcon.Information)
    End Sub
    End Class

