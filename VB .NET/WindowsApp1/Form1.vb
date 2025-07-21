Imports System
Public Class Form1
    Private WithEvents btnClickMe As New Button()
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        btnClickMe.Text = "Click Me"
        btnClickMe.Size = New Size(100, 40)
        btnClickMe.Location = New Point(100, 100)

        Me.Controls.Add(btnClickMe)
    End Sub
    Private Sub btnClickMe_Click(sender As Object, e As EventArgs) Handles btnClickMe.Click

        Dim members As String = " Hello" & vbCrLf & vbCrLf &
                "Group Members: " & vbCrLf &
                "1. Yong Yuan Lin - A24DW0325" & vbCrLf &
                "2. Marcus Lai Wei Ze - A24DW283" & vbCrLf &
                "3. Chung Wei Kit - A24DW0132" & vbCrLf &
                "4. Tiong Yong Hern - A24DW0106" & vbCrLf &
                "5. AQIL NAZHAN BIN ROSAZIZI - A24DW0460"

        MessageBox.Show(members, "Group Info", MessageBoxButtons.OK, MessageBoxIcon.Information)
    End Sub
End Class