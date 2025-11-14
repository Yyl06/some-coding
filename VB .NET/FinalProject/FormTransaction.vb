Imports System.IO
Public Class FormTransaction
    Private Sub frmTransactions_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        lstTransactions.Items.Clear()
        If File.Exists("transactions.txt") Then
            For Each line As String In File.ReadAllLines("transactions.txt")
                lstTransactions.Items.Add(line)
            Next
        Else
            lstTransactions.Items.Add("No transactions recorded.")
        End If
    End Sub

    Private Sub btnBack_Click(sender As Object, e As EventArgs) Handles btnBack.Click
        MainUI.Show()
        Me.Hide()
    End Sub
End Class