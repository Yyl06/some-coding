Public Class MainUI
    Private Sub btnCashier_Click(sender As Object, e As EventArgs) Handles btnCashier.Click
        FormCashier.Show()
        Me.Hide()
    End Sub
    Private Sub btnTransactions_Click(sender As Object, e As EventArgs) Handles btnTransactions.Click
        FormTransaction.Show()
        Me.Hide()
    End Sub
    Private Sub btnReport_Click(sender As Object, e As EventArgs) Handles btnReport.Click
        FormReport.Show()
        Me.Hide()
    End Sub
    Private Sub btnExit_Click(sender As Object, e As EventArgs) Handles btnExit.Click
        Application.Exit()
    End Sub
    Private Sub frmMain_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        Application.Exit()
    End Sub
    Private Sub btnLogout_Click(sender As Object, e As EventArgs) Handles btnLogout.Click
        Dim result As DialogResult = MessageBox.Show("Logout from system?", "Confirm Logout", MessageBoxButtons.YesNo, MessageBoxIcon.Question)
        If result = DialogResult.Yes Then
            Me.Hide()
            Login.txtUser.Clear()
            Login.txtPass.Clear()
            Login.lblMessage.Text = ""
            Login.Show()
        End If
    End Sub
End Class
