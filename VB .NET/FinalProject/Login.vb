Imports MySql.Data.MySqlClient

Public Class Login
    Private Sub FormLogin_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ConnectDB()
    End Sub

    Private Sub btnLogin_Click(sender As Object, e As EventArgs) Handles btnLogin.Click
        Dim username As String = txtUser.Text.Trim()
        Dim password As String = txtPass.Text.Trim()

        If username = "" Or password = "" Then
            lblMessage.Text = "Please enter username and password."
            lblMessage.ForeColor = Color.Red
            Exit Sub
        End If

        Try
            Dim query As String = "SELECT * FROM users WHERE username=@user AND password=@pass"
            Dim cmd As New MySqlCommand(query, conn)
            cmd.Parameters.AddWithValue("@user", username)
            cmd.Parameters.AddWithValue("@pass", password)

            Dim reader As MySqlDataReader = cmd.ExecuteReader()

            If reader.Read() Then
                Dim role As String = reader("role").ToString()
                reader.Close()

                MessageBox.Show("Welcome, " & username & "!", "Login Successful", MessageBoxButtons.OK, MessageBoxIcon.Information)

                Me.Hide()
                FormCashier.lblUserInfo.Text = "Logged in as: " & username & " (" & role & ")"
                FormCashier.Show()
            Else
                reader.Close()
                lblMessage.Text = "Invalid username or password!"
                lblMessage.ForeColor = Color.Red
            End If
        Catch ex As Exception
            MessageBox.Show("Error: " & ex.Message)
        End Try
    End Sub
End Class
