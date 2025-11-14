Imports MySql.Data.MySqlClient
Module DBConnectionHelper
    Public conn As MySqlConnection

    Public Sub ConnectDB()
        Try
            Dim connectionString As String = "server=localhost;userid=root;password=;database=cashierdb"
            conn = New MySqlConnection(connectionString)
            conn.Open()
        Catch ex As Exception
            MessageBox.Show("Database connection failed: " & ex.Message)
        Finally
            conn.Close()
        End Try
    End Sub
End Module
